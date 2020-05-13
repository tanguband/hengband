﻿#include "angband.h"
#include "core/player-processor.h"
#include "player-move.h"
#include "player-skill.h"
#include "core/special-internal-keys.h"
#include "mutation/mutation.h"
#include "spell/spells2.h" // 相互依存している。後でどうするか検討する.
#include "monster-status.h"
#include "view/display-main-window.h"
#include "creature.h"
#include "player-effects.h"
#include "core/stuff-handler.h"
#include "inventory/pack-overflow.h"
#include "io/input-key-processor.h"
#include "snipe.h"
#include "realm/realm-hex.h"
#include "spell/music-checker.h"
#include "monsterrace-hook.h"
#include "wild.h"

bool load = TRUE;
bool can_save = FALSE;
bool repair_monsters; // todo より適切なファイルへ移設する可能性あり.

static void process_fishing(player_type* creature_ptr)
{
    Term_xtra(TERM_XTRA_DELAY, 10);
    if (one_in_(1000)) {
        MONRACE_IDX r_idx;
        bool success = FALSE;
        get_mon_num_prep(creature_ptr, monster_is_fishing_target, NULL);
        r_idx = get_mon_num(creature_ptr, creature_ptr->current_floor_ptr->dun_level ? creature_ptr->current_floor_ptr->dun_level : wilderness[creature_ptr->wilderness_y][creature_ptr->wilderness_x].level, 0);
        msg_print(NULL);
        if (r_idx && one_in_(2)) {
            POSITION y, x;
            y = creature_ptr->y + ddy[creature_ptr->fishing_dir];
            x = creature_ptr->x + ddx[creature_ptr->fishing_dir];
            if (place_monster_aux(creature_ptr, 0, y, x, r_idx, PM_NO_KAGE)) {
                GAME_TEXT m_name[MAX_NLEN];
                monster_desc(creature_ptr, m_name, &creature_ptr->current_floor_ptr->m_list[creature_ptr->current_floor_ptr->grid_array[y][x].m_idx], 0);
                msg_format(_("%sが釣れた！", "You have a good catch!"), m_name);
                success = TRUE;
            }
        }

        if (!success) {
            msg_print(_("餌だけ食われてしまった！くっそ～！", "Damn!  The fish stole your bait!"));
        }

        disturb(creature_ptr, FALSE, TRUE);
    }
}

/*!
 * @brief プレイヤーの行動処理 / Process the player
 * @return なし
 * @note
 * Notice the annoying code to handle "pack overflow", which\n
 * must come first just in case somebody manages to corrupt\n
 * the savefiles by clever use of menu commands or something.\n
 */
void process_player(player_type *creature_ptr)
{
    if (creature_ptr->hack_mutation) {
        msg_print(_("何か変わった気がする！", "You feel different!"));

        (void)gain_mutation(creature_ptr, 0);
        creature_ptr->hack_mutation = FALSE;
    }

    if (creature_ptr->invoking_midnight_curse) {
        int count = 0;
        activate_ty_curse(creature_ptr, FALSE, &count);
        creature_ptr->invoking_midnight_curse = FALSE;
    }

    if (creature_ptr->phase_out) {
        for (MONSTER_IDX m_idx = 1; m_idx < creature_ptr->current_floor_ptr->m_max; m_idx++) {
            monster_type* m_ptr = &creature_ptr->current_floor_ptr->m_list[m_idx];
            if (!monster_is_valid(m_ptr))
                continue;

            m_ptr->mflag2 |= (MFLAG2_MARK | MFLAG2_SHOW);
            update_monster(creature_ptr, m_idx, FALSE);
        }

        print_time(creature_ptr);
    } else if (!(load && creature_ptr->energy_need <= 0)) {
        creature_ptr->energy_need -= SPEED_TO_ENERGY(creature_ptr->pspeed);
    }

    if (creature_ptr->energy_need > 0)
        return;
    if (!command_rep)
        print_time(creature_ptr);

    if (creature_ptr->resting < 0) {
        if (creature_ptr->resting == COMMAND_ARG_REST_FULL_HEALING) {
            if ((creature_ptr->chp == creature_ptr->mhp) && (creature_ptr->csp >= creature_ptr->msp)) {
                set_action(creature_ptr, ACTION_NONE);
            }
        } else if (creature_ptr->resting == COMMAND_ARG_REST_UNTIL_DONE) {
            if ((creature_ptr->chp == creature_ptr->mhp) && (creature_ptr->csp >= creature_ptr->msp) && !creature_ptr->blind && !creature_ptr->confused && !creature_ptr->poisoned && !creature_ptr->afraid && !creature_ptr->stun && !creature_ptr->cut && !creature_ptr->slow && !creature_ptr->paralyzed && !creature_ptr->image && !creature_ptr->word_recall && !creature_ptr->alter_reality) {
                set_action(creature_ptr, ACTION_NONE);
            }
        }
    }

    if (creature_ptr->action == ACTION_FISH)
        process_fishing(creature_ptr);

    if (check_abort) {
        if (creature_ptr->running || travel.run || command_rep || (creature_ptr->action == ACTION_REST) || (creature_ptr->action == ACTION_FISH)) {
            inkey_scan = TRUE;
            if (inkey()) {
                flush();
                disturb(creature_ptr, FALSE, TRUE);
                msg_print(_("中断しました。", "Canceled."));
            }
        }
    }

    if (creature_ptr->riding && !creature_ptr->confused && !creature_ptr->blind) {
        monster_type* m_ptr = &creature_ptr->current_floor_ptr->m_list[creature_ptr->riding];
        monster_race* r_ptr = &r_info[m_ptr->r_idx];
        if (MON_CSLEEP(m_ptr)) {
            GAME_TEXT m_name[MAX_NLEN];
            (void)set_monster_csleep(creature_ptr, creature_ptr->riding, 0);
            monster_desc(creature_ptr, m_name, m_ptr, 0);
            msg_format(_("%^sを起こした。", "You have woken %s up."), m_name);
        }

        if (MON_STUNNED(m_ptr)) {
            if (set_monster_stunned(creature_ptr, creature_ptr->riding,
                    (randint0(r_ptr->level) < creature_ptr->skill_exp[GINOU_RIDING]) ? 0 : (MON_STUNNED(m_ptr) - 1))) {
                GAME_TEXT m_name[MAX_NLEN];
                monster_desc(creature_ptr, m_name, m_ptr, 0);
                msg_format(_("%^sを朦朧状態から立ち直らせた。", "%^s is no longer stunned."), m_name);
            }
        }

        if (MON_CONFUSED(m_ptr)) {
            if (set_monster_confused(creature_ptr, creature_ptr->riding,
                    (randint0(r_ptr->level) < creature_ptr->skill_exp[GINOU_RIDING]) ? 0 : (MON_CONFUSED(m_ptr) - 1))) {
                GAME_TEXT m_name[MAX_NLEN];
                monster_desc(creature_ptr, m_name, m_ptr, 0);
                msg_format(_("%^sを混乱状態から立ち直らせた。", "%^s is no longer confused."), m_name);
            }
        }

        if (MON_MONFEAR(m_ptr)) {
            if (set_monster_monfear(creature_ptr, creature_ptr->riding,
                    (randint0(r_ptr->level) < creature_ptr->skill_exp[GINOU_RIDING]) ? 0 : (MON_MONFEAR(m_ptr) - 1))) {
                GAME_TEXT m_name[MAX_NLEN];
                monster_desc(creature_ptr, m_name, m_ptr, 0);
                msg_format(_("%^sを恐怖から立ち直らせた。", "%^s is no longer afraid."), m_name);
            }
        }

        handle_stuff(creature_ptr);
    }

    load = FALSE;
    if (creature_ptr->lightspeed) {
        (void)set_lightspeed(creature_ptr, creature_ptr->lightspeed - 1, TRUE);
    }

    if ((creature_ptr->pclass == CLASS_FORCETRAINER) && P_PTR_KI) {
        if (P_PTR_KI < 40)
            P_PTR_KI = 0;
        else
            P_PTR_KI -= 40;
        creature_ptr->update |= (PU_BONUS);
    }

    if (creature_ptr->action == ACTION_LEARN) {
        s32b cost = 0L;
        u32b cost_frac = (creature_ptr->msp + 30L) * 256L;
        s64b_LSHIFT(cost, cost_frac, 16);
        if (s64b_cmp(creature_ptr->csp, creature_ptr->csp_frac, cost, cost_frac) < 0) {
            creature_ptr->csp = 0;
            creature_ptr->csp_frac = 0;
            set_action(creature_ptr, ACTION_NONE);
        } else {
            s64b_sub(&(creature_ptr->csp), &(creature_ptr->csp_frac), cost, cost_frac);
        }

        creature_ptr->redraw |= PR_MANA;
    }

    if (creature_ptr->special_defense & KATA_MASK) {
        if (creature_ptr->special_defense & KATA_MUSOU) {
            if (creature_ptr->csp < 3) {
                set_action(creature_ptr, ACTION_NONE);
            } else {
                creature_ptr->csp -= 2;
                creature_ptr->redraw |= (PR_MANA);
            }
        }
    }

    /*** Handle actual user input ***/
    while (creature_ptr->energy_need <= 0) {
        creature_ptr->window |= PW_PLAYER;
        creature_ptr->sutemi = FALSE;
        creature_ptr->counter = FALSE;
        creature_ptr->now_damaged = FALSE;

        handle_stuff(creature_ptr);
        move_cursor_relative(creature_ptr->y, creature_ptr->x);
        if (fresh_before)
            Term_fresh();

        pack_overflow(creature_ptr);
        if (!command_new)
            command_see = FALSE;

        free_turn(creature_ptr);
        if (creature_ptr->phase_out) {
            move_cursor_relative(creature_ptr->y, creature_ptr->x);
            command_cmd = SPECIAL_KEY_BUILDING;
            process_command(creature_ptr);
        } else if (creature_ptr->paralyzed || (creature_ptr->stun >= 100)) {
            take_turn(creature_ptr, 100);
        } else if (creature_ptr->action == ACTION_REST) {
            if (creature_ptr->resting > 0) {
                creature_ptr->resting--;
                if (!creature_ptr->resting)
                    set_action(creature_ptr, ACTION_NONE);
                creature_ptr->redraw |= (PR_STATE);
            }

            take_turn(creature_ptr, 100);
        } else if (creature_ptr->action == ACTION_FISH) {
            take_turn(creature_ptr, 100);
        } else if (creature_ptr->running) {
            run_step(creature_ptr, 0);
        } else if (travel.run) {
            travel_step(creature_ptr);
        } else if (command_rep) {
            command_rep--;
            creature_ptr->redraw |= (PR_STATE);
            handle_stuff(creature_ptr);
            msg_flag = FALSE;
            prt("", 0, 0);
            process_command(creature_ptr);
        } else {
            move_cursor_relative(creature_ptr->y, creature_ptr->x);
            can_save = TRUE;
            request_command(creature_ptr, FALSE);
            can_save = FALSE;
            process_command(creature_ptr);
        }

        pack_overflow(creature_ptr);
        if (creature_ptr->energy_use) {
            if (creature_ptr->timewalk || creature_ptr->energy_use > 400) {
                creature_ptr->energy_need += creature_ptr->energy_use * TURNS_PER_TICK / 10;
            } else {
                creature_ptr->energy_need += (s16b)((s32b)creature_ptr->energy_use * ENERGY_NEED() / 100L);
            }

            if (creature_ptr->image)
                creature_ptr->redraw |= (PR_MAP);

            for (MONSTER_IDX m_idx = 1; m_idx < creature_ptr->current_floor_ptr->m_max; m_idx++) {
                monster_type* m_ptr;
                monster_race* r_ptr;
                m_ptr = &creature_ptr->current_floor_ptr->m_list[m_idx];
                if (!monster_is_valid(m_ptr))
                    continue;
                if (!m_ptr->ml)
                    continue;

                r_ptr = &r_info[m_ptr->ap_r_idx];
                if (!(r_ptr->flags1 & (RF1_ATTR_MULTI | RF1_SHAPECHANGER)))
                    continue;

                lite_spot(creature_ptr, m_ptr->fy, m_ptr->fx);
            }

            if (repair_monsters) {
                repair_monsters = FALSE;
                for (MONSTER_IDX m_idx = 1; m_idx < creature_ptr->current_floor_ptr->m_max; m_idx++) {
                    monster_type* m_ptr;
                    m_ptr = &creature_ptr->current_floor_ptr->m_list[m_idx];
                    if (!monster_is_valid(m_ptr))
                        continue;

                    if (m_ptr->mflag & MFLAG_NICE) {
                        m_ptr->mflag &= ~(MFLAG_NICE);
                    }

                    if (m_ptr->mflag2 & MFLAG2_MARK) {
                        if (m_ptr->mflag2 & MFLAG2_SHOW) {
                            m_ptr->mflag2 &= ~(MFLAG2_SHOW);
                            repair_monsters = TRUE;
                        } else {
                            m_ptr->mflag2 &= ~(MFLAG2_MARK);
                            m_ptr->ml = FALSE;
                            update_monster(creature_ptr, m_idx, FALSE);
                            if (creature_ptr->health_who == m_idx)
                                creature_ptr->redraw |= (PR_HEALTH);
                            if (creature_ptr->riding == m_idx)
                                creature_ptr->redraw |= (PR_UHEALTH);

                            lite_spot(creature_ptr, m_ptr->fy, m_ptr->fx);
                        }
                    }
                }
            }

            if (creature_ptr->pclass == CLASS_IMITATOR) {
                if (creature_ptr->mane_num > (creature_ptr->lev > 44 ? 3 : creature_ptr->lev > 29 ? 2 : 1)) {
                    creature_ptr->mane_num--;
                    for (int j = 0; j < creature_ptr->mane_num; j++) {
                        creature_ptr->mane_spell[j] = creature_ptr->mane_spell[j + 1];
                        creature_ptr->mane_dam[j] = creature_ptr->mane_dam[j + 1];
                    }
                }

                creature_ptr->new_mane = FALSE;
                creature_ptr->redraw |= (PR_IMITATION);
            }

            if (creature_ptr->action == ACTION_LEARN) {
                creature_ptr->new_mane = FALSE;
                creature_ptr->redraw |= (PR_STATE);
            }

            if (creature_ptr->timewalk && (creature_ptr->energy_need > -1000)) {

                creature_ptr->redraw |= (PR_MAP);
                creature_ptr->update |= (PU_MONSTERS);
                creature_ptr->window |= (PW_OVERHEAD | PW_DUNGEON);

                msg_print(_("「時は動きだす…」", "You feel time flowing around you once more."));
                msg_print(NULL);
                creature_ptr->timewalk = FALSE;
                creature_ptr->energy_need = ENERGY_NEED();

                handle_stuff(creature_ptr);
            }
        }

        if (!creature_ptr->playing || creature_ptr->is_dead) {
            creature_ptr->timewalk = FALSE;
            break;
        }

        if (creature_ptr->energy_use && creature_ptr->reset_concent)
            reset_concentration(creature_ptr, TRUE);

        if (creature_ptr->leaving)
            break;
    }

    update_smell(creature_ptr->current_floor_ptr, creature_ptr);
}

/*!
 * @brief プレイヤーの行動エネルギーが充填される（＝プレイヤーのターンが回る）毎に行われる処理  / process the effects per 100 energy at player speed.
 * @return なし
 */
void process_upkeep_with_speed(player_type *creature_ptr)
{
    if (!load && creature_ptr->enchant_energy_need > 0 && !creature_ptr->leaving) {
        creature_ptr->enchant_energy_need -= SPEED_TO_ENERGY(creature_ptr->pspeed);
    }

    if (creature_ptr->enchant_energy_need > 0)
        return;

    while (creature_ptr->enchant_energy_need <= 0) {
        if (!load)
            check_music(creature_ptr);
        if (!load)
            check_hex(creature_ptr);
        if (!load)
            revenge_spell(creature_ptr);

        creature_ptr->enchant_energy_need += ENERGY_NEED();
    }
}