#include "market/articles-on-sale.h"
#include "sv-definition/sv-amulet-types.h"
#include "sv-definition/sv-armor-types.h"
#include "sv-definition/sv-bow-types.h"
#include "sv-definition/sv-digging-types.h"
#include "sv-definition/sv-food-types.h"
#include "sv-definition/sv-other-types.h"
#include "sv-definition/sv-lite-types.h"
#include "sv-definition/sv-potion-types.h"
#include "sv-definition/sv-protector-types.h"
#include "sv-definition/sv-scroll-types.h"
#include "sv-definition/sv-ring-types.h"
#include "sv-definition/sv-rod-types.h"
#include "sv-definition/sv-staff-types.h"
#include "sv-definition/sv-wand-types.h"
#include "sv-definition/sv-weapon-types.h"

/*!
 * @brief 店舗で常時販売するオブジェクトを定義する 
 * @detail
 * 上から優先して配置する。
 * 重複して同じ商品を設定した場合、数量が増える。
 * 17エントリーまで設定可能。(最後は TV_NONE で止める)
 * 種類が多すぎる場合、店舗を埋めつくすので注意。
 */
store_stock_item_type store_regular_table[MAX_STORES][STORE_MAX_KEEP] =
{ 
	{
        /* General Store */
        { TV_FOOD, SV_FOOD_RATION },
        { TV_LITE, SV_LITE_TORCH },
        { TV_LITE, SV_LITE_LANTERN },
        { TV_FLASK, SV_FLASK_OIL },
        { TV_POTION, SV_POTION_WATER },
        { TV_SPIKE, 0 },
        { TV_NONE, 0 },
    },
    {
        /* Armoury */
        { TV_NONE, 0 },
    },
    {
        /* Weaponsmith */
        { TV_HISSATSU_BOOK, 0 },
        { TV_SHOT, SV_AMMO_NORMAL },
        { TV_SHOT, SV_AMMO_NORMAL },
        { TV_ARROW, SV_AMMO_NORMAL },
        { TV_ARROW, SV_AMMO_NORMAL },
        { TV_BOLT, SV_AMMO_NORMAL },
        { TV_BOLT, SV_AMMO_NORMAL },
        { TV_NONE, 0 },
    },
    {
        /* Temple */
        { TV_POTION, SV_POTION_CURE_CRITICAL },
        { TV_POTION, SV_POTION_CURE_SERIOUS },
        { TV_POTION, SV_POTION_HEROISM },
        { TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
        { TV_SCROLL, SV_SCROLL_REMOVE_CURSE },
        { TV_LIFE_BOOK, 0 },
        { TV_CRUSADE_BOOK, 0 },
        { TV_NONE, 0 },
    },
    {
        /* Alchemy shop */
        { TV_SCROLL, SV_SCROLL_PHASE_DOOR },
        { TV_SCROLL, SV_SCROLL_PHASE_DOOR },
        { TV_SCROLL, SV_SCROLL_TELEPORT },
        { TV_SCROLL, SV_SCROLL_TELEPORT },
        { TV_SCROLL, SV_SCROLL_RECHARGING },
        { TV_SCROLL, SV_SCROLL_IDENTIFY },
        { TV_SCROLL, SV_SCROLL_DETECT_GOLD },
        { TV_NONE, 0 },
    },
    {
        /* Magic User */
        { TV_STAFF, SV_STAFF_IDENTIFY },
        { TV_STAFF, SV_STAFF_IDENTIFY },
        { TV_STAFF, SV_STAFF_MAPPING },
        { TV_ARCANE_BOOK, 0 },
        { TV_SORCERY_BOOK, 0 },
        { TV_NONE, 0 },
    },
    {
        /* Blackmarket */
        { TV_NONE, 0 },
    },
    {
        /* Home */
        { TV_NONE, 0 },
    },
    {
        /* Bookstore */
        { TV_SORCERY_BOOK, 0 },
        { TV_NATURE_BOOK, 0 },
        { TV_CHAOS_BOOK, 0 },
        { TV_DEATH_BOOK, 0 },
        { TV_TRUMP_BOOK, 0 },
        { TV_ARCANE_BOOK, 0 },
        { TV_CRAFT_BOOK, 0 },
        { TV_DEMON_BOOK, 0 },
        { TV_MUSIC_BOOK, 0 },
        { TV_HEX_BOOK, 0 },
        { TV_NONE, 0 },
    },
    {
        /* Museum */
        { TV_NONE, 0 },
    },
};

/*!
 * @brief 店舗でランダム販売するオブジェクトを定義する
 * @detail tval/svalのペア
 */
store_stock_item_type store_table[MAX_STORES][STORE_CHOICES] =
{
	{
		/* General Store */
		{ TV_FOOD, SV_FOOD_RATION },
		{ TV_FOOD, SV_FOOD_RATION },
		{ TV_FOOD, SV_FOOD_RATION },
		{ TV_FOOD, SV_FOOD_RATION },

		{ TV_FOOD, SV_FOOD_BISCUIT },
		{ TV_FOOD, SV_FOOD_JERKY },
		{ TV_FOOD, SV_FOOD_PINT_OF_WINE },
		{ TV_FOOD, SV_FOOD_PINT_OF_ALE },

		{ TV_LITE, SV_LITE_TORCH },
		{ TV_LITE, SV_LITE_TORCH },
		{ TV_LITE, SV_LITE_LANTERN },
		{ TV_LITE, SV_LITE_LANTERN },

		{ TV_POTION, SV_POTION_WATER },
		{ TV_POTION, SV_POTION_WATER },
		{ TV_FOOD, SV_FOOD_WAYBREAD },
		{ TV_FOOD, SV_FOOD_WAYBREAD },

		{ TV_FLASK, 0 },
		{ TV_FLASK, 0 },
		{ TV_SPIKE, 0 },
		{ TV_SPIKE, 0 },

		{ TV_SPIKE, 0 },
		{ TV_SPIKE, 0 },
		{ TV_SHOT, SV_AMMO_NORMAL },
		{ TV_SHOT, SV_AMMO_NORMAL },

		{ TV_ARROW, SV_AMMO_NORMAL },
		{ TV_ARROW, SV_AMMO_NORMAL },
		{ TV_BOLT, SV_AMMO_NORMAL },
		{ TV_BOLT, SV_AMMO_NORMAL },

		{ TV_DIGGING, SV_SHOVEL },
		{ TV_DIGGING, SV_SHOVEL },
		{ TV_DIGGING, SV_PICK },
		{ TV_CLOAK, SV_CLOAK },

		{ TV_CLOAK, SV_CLOAK },
		{ TV_CLOAK, SV_FUR_CLOAK },
		{ TV_CAPTURE, 0 },
		{ TV_CAPTURE, 0 },

		{ TV_FIGURINE, 0 },
        { TV_WHISTLE, 1 },
        { TV_ROD, SV_ROD_PESTICIDE },
        { TV_STATUE, SV_ANY },

		{ TV_NONE, 0 },
        { TV_NONE, 0 },
        { TV_NONE, 0 },
        { TV_NONE, 0 },

		{ TV_NONE, 0 },
        { TV_NONE, 0 },
        { TV_NONE, 0 },
        { TV_NONE, 0 },
	},

	{
		/* Armoury */
		{ TV_BOOTS, SV_PAIR_OF_SOFT_LEATHER_BOOTS },
		{ TV_BOOTS, SV_PAIR_OF_SOFT_LEATHER_BOOTS },
		{ TV_BOOTS, SV_PAIR_OF_HARD_LEATHER_BOOTS },
		{ TV_BOOTS, SV_PAIR_OF_HARD_LEATHER_BOOTS },

		{ TV_HELM, SV_HARD_LEATHER_CAP },
		{ TV_HELM, SV_HARD_LEATHER_CAP },
		{ TV_HELM, SV_METAL_CAP },
		{ TV_HELM, SV_IRON_HELM },

		{ TV_SOFT_ARMOR, SV_ROBE },
		{ TV_SOFT_ARMOR, SV_ROBE },
		{ TV_SOFT_ARMOR, SV_SOFT_LEATHER_ARMOR },
		{ TV_SOFT_ARMOR, SV_SOFT_LEATHER_ARMOR },

		{ TV_SOFT_ARMOR, SV_HARD_LEATHER_ARMOR },
		{ TV_SOFT_ARMOR, SV_HARD_LEATHER_ARMOR },
		{ TV_SOFT_ARMOR, SV_HARD_STUDDED_LEATHER },
		{ TV_SOFT_ARMOR, SV_HARD_STUDDED_LEATHER },

		{ TV_SOFT_ARMOR, SV_RHINO_HIDE_ARMOR },
		{ TV_SOFT_ARMOR, SV_LEATHER_SCALE_MAIL },
		{ TV_HARD_ARMOR, SV_METAL_SCALE_MAIL },
		{ TV_HARD_ARMOR, SV_CHAIN_MAIL },

		{ TV_HARD_ARMOR, SV_DOUBLE_RING_MAIL },
		{ TV_HARD_ARMOR, SV_AUGMENTED_CHAIN_MAIL },
		{ TV_HARD_ARMOR, SV_BAR_CHAIN_MAIL },
		{ TV_HARD_ARMOR, SV_DOUBLE_CHAIN_MAIL },

		{ TV_HARD_ARMOR, SV_METAL_BRIGANDINE_ARMOUR },
		{ TV_HARD_ARMOR, SV_SPLINT_MAIL },
		{ TV_GLOVES, SV_SET_OF_LEATHER_GLOVES },
		{ TV_GLOVES, SV_SET_OF_LEATHER_GLOVES },

		{ TV_GLOVES, SV_SET_OF_GAUNTLETS },
		{ TV_SHIELD, SV_SMALL_LEATHER_SHIELD },
		{ TV_SHIELD, SV_LARGE_LEATHER_SHIELD },
		{ TV_SHIELD, SV_SMALL_METAL_SHIELD },

		{ TV_BOOTS, SV_PAIR_OF_HARD_LEATHER_BOOTS },
		{ TV_BOOTS, SV_PAIR_OF_HARD_LEATHER_BOOTS },
		{ TV_HELM, SV_HARD_LEATHER_CAP },
		{ TV_HELM, SV_HARD_LEATHER_CAP },

		{ TV_SOFT_ARMOR, SV_ROBE },
		{ TV_SOFT_ARMOR, SV_SOFT_LEATHER_ARMOR },
		{ TV_SOFT_ARMOR, SV_SOFT_LEATHER_ARMOR },
		{ TV_SOFT_ARMOR, SV_HARD_LEATHER_ARMOR },

		{ TV_SOFT_ARMOR, SV_LEATHER_JACK },
		{ TV_HARD_ARMOR, SV_METAL_SCALE_MAIL },
		{ TV_HARD_ARMOR, SV_CHAIN_MAIL },
		{ TV_HARD_ARMOR, SV_CHAIN_MAIL },

		{ TV_GLOVES, SV_SET_OF_LEATHER_GLOVES },
		{ TV_GLOVES, SV_SET_OF_GAUNTLETS },
		{ TV_SHIELD, SV_SMALL_LEATHER_SHIELD },
		{ TV_SHIELD, SV_SMALL_LEATHER_SHIELD }
	},

	{
		/* Weaponsmith */
		{ TV_SWORD, SV_DAGGER },
		{ TV_SWORD, SV_MAIN_GAUCHE },
		{ TV_SWORD, SV_RAPIER },
		{ TV_SWORD, SV_SMALL_SWORD },

		{ TV_SWORD, SV_SHORT_SWORD },
		{ TV_SWORD, SV_SABRE },
		{ TV_SWORD, SV_CUTLASS },
		{ TV_SWORD, SV_TULWAR },

		{ TV_SWORD, SV_BROAD_SWORD },
		{ TV_SWORD, SV_LONG_SWORD },
		{ TV_SWORD, SV_SCIMITAR },
		{ TV_SWORD, SV_KATANA },

		{ TV_SWORD, SV_BASTARD_SWORD },
		{ TV_POLEARM, SV_SPEAR },
		{ TV_POLEARM, SV_AWL_PIKE },
		{ TV_POLEARM, SV_TRIDENT },

		{ TV_POLEARM, SV_PIKE },
		{ TV_POLEARM, SV_BEAKED_AXE },
		{ TV_POLEARM, SV_BROAD_AXE },
		{ TV_POLEARM, SV_LANCE },

		{ TV_POLEARM, SV_BATTLE_AXE },
		{ TV_POLEARM, SV_HATCHET },
		{ TV_BOW, SV_SLING },
		{ TV_BOW, SV_SHORT_BOW },

		{ TV_BOW, SV_LIGHT_XBOW },
		{ TV_SHOT, SV_AMMO_NORMAL },
		{ TV_SHOT, SV_AMMO_NORMAL },
		{ TV_ARROW, SV_AMMO_NORMAL },

		{ TV_ARROW, SV_AMMO_NORMAL },
		{ TV_BOLT, SV_AMMO_NORMAL },
		{ TV_BOLT, SV_AMMO_NORMAL },
		{ TV_BOW, SV_LIGHT_XBOW },

		{ TV_ARROW, SV_AMMO_NORMAL },
		{ TV_BOLT, SV_AMMO_NORMAL },
		{ TV_BOW, SV_SHORT_BOW },
		{ TV_BOW, SV_LIGHT_XBOW },

		{ TV_SWORD, SV_DAGGER },
		{ TV_SWORD, SV_TANTO },
		{ TV_SWORD, SV_RAPIER },
		{ TV_SWORD, SV_SMALL_SWORD },

		{ TV_SWORD, SV_SHORT_SWORD },
		{ TV_SWORD, SV_LONG_SWORD },
		{ TV_SWORD, SV_SCIMITAR },
		{ TV_SWORD, SV_BROAD_SWORD },

		{ TV_HISSATSU_BOOK, 0 },
		{ TV_HISSATSU_BOOK, 0 },
		{ TV_HISSATSU_BOOK, 1 },
		{ TV_HISSATSU_BOOK, 1 },
	},

	{
		/* Temple */
		{ TV_HAFTED, SV_NUNCHAKU },
		{ TV_HAFTED, SV_QUARTERSTAFF },
		{ TV_HAFTED, SV_MACE },
		{ TV_HAFTED, SV_BO_STAFF },

		{ TV_HAFTED, SV_WAR_HAMMER },
		{ TV_HAFTED, SV_WAR_HAMMER },
		{ TV_HAFTED, SV_MORNING_STAR },
		{ TV_HAFTED, SV_FLAIL },

		{ TV_HAFTED, SV_LEAD_FILLED_MACE },
		{ TV_SCROLL, SV_SCROLL_REMOVE_CURSE },
		{ TV_SCROLL, SV_SCROLL_BLESSING },
		{ TV_SCROLL, SV_SCROLL_HOLY_CHANT },

		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
        { TV_POTION, SV_POTION_CURE_LIGHT },

		{ TV_POTION, SV_POTION_HEROISM },
		{ TV_POTION, SV_POTION_HEROISM },
		{ TV_POTION, SV_POTION_CURE_SERIOUS },
		{ TV_POTION, SV_POTION_CURE_SERIOUS },

		{ TV_POTION, SV_POTION_CURE_CRITICAL },
		{ TV_POTION, SV_POTION_CURE_CRITICAL },
		{ TV_POTION, SV_POTION_CURE_CRITICAL },
		{ TV_POTION, SV_POTION_CURE_CRITICAL },

		{ TV_POTION, SV_POTION_RESTORE_EXP },
		{ TV_POTION, SV_POTION_RESTORE_EXP },
		{ TV_POTION, SV_POTION_RESTORE_EXP },
		{ TV_POTION, SV_POTION_RESTORE_EXP },

		{ TV_LIFE_BOOK, 0 },
		{ TV_LIFE_BOOK, 1 },
		{ TV_LIFE_BOOK, 1 },
		{ TV_LIFE_BOOK, 1 },

		{ TV_CRUSADE_BOOK, 0 },
		{ TV_CRUSADE_BOOK, 1 },
		{ TV_CRUSADE_BOOK, 1 },
		{ TV_CRUSADE_BOOK, 1 },

		{ TV_HAFTED, SV_WHIP },
		{ TV_HAFTED, SV_MACE },
		{ TV_HAFTED, SV_BALL_AND_CHAIN },
		{ TV_HAFTED, SV_WAR_HAMMER },

		{ TV_POTION, SV_POTION_RESIST_HEAT },
		{ TV_POTION, SV_POTION_RESIST_COLD },
		{ TV_FIGURINE, 0 },
		{ TV_STATUE, SV_ANY },

		{ TV_SCROLL, SV_SCROLL_REMOVE_CURSE },
		{ TV_SCROLL, SV_SCROLL_REMOVE_CURSE },
		{ TV_SCROLL, SV_SCROLL_STAR_REMOVE_CURSE },
		{ TV_SCROLL, SV_SCROLL_STAR_REMOVE_CURSE },
	},

	{
		/* Alchemy shop */
		{ TV_SCROLL, SV_SCROLL_ENCHANT_WEAPON_TO_HIT },
		{ TV_SCROLL, SV_SCROLL_ENCHANT_WEAPON_TO_DAM },
		{ TV_SCROLL, SV_SCROLL_ENCHANT_ARMOR },
		{ TV_SCROLL, SV_SCROLL_IDENTIFY },

		{ TV_SCROLL, SV_SCROLL_IDENTIFY },
		{ TV_SCROLL, SV_SCROLL_IDENTIFY },
		{ TV_SCROLL, SV_SCROLL_IDENTIFY },
		{ TV_SCROLL, SV_SCROLL_LIGHT },

		{ TV_SCROLL, SV_SCROLL_PHASE_DOOR },
		{ TV_SCROLL, SV_SCROLL_PHASE_DOOR },
		{ TV_SCROLL, SV_SCROLL_TELEPORT },
		{ TV_SCROLL, SV_SCROLL_MONSTER_CONFUSION },

		{ TV_SCROLL, SV_SCROLL_MAPPING },
		{ TV_SCROLL, SV_SCROLL_DETECT_GOLD },
		{ TV_SCROLL, SV_SCROLL_DETECT_ITEM },
		{ TV_SCROLL, SV_SCROLL_DETECT_TRAP },

		{ TV_SCROLL, SV_SCROLL_DETECT_INVIS },
		{ TV_SCROLL, SV_SCROLL_RECHARGING },
		{ TV_SCROLL, SV_SCROLL_TELEPORT },
		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },

		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
		{ TV_SCROLL, SV_SCROLL_WORD_OF_RECALL },
		{ TV_SCROLL, SV_SCROLL_TELEPORT },

		{ TV_SCROLL, SV_SCROLL_TELEPORT },
		{ TV_POTION, SV_POTION_RES_STR },
		{ TV_POTION, SV_POTION_RES_INT },
		{ TV_POTION, SV_POTION_RES_WIS },

		{ TV_POTION, SV_POTION_RES_DEX },
		{ TV_POTION, SV_POTION_RES_CON },
		{ TV_POTION, SV_POTION_RES_CHR },
		{ TV_SCROLL, SV_SCROLL_IDENTIFY },

		{ TV_SCROLL, SV_SCROLL_IDENTIFY },
		{ TV_SCROLL, SV_SCROLL_STAR_IDENTIFY },
		{ TV_SCROLL, SV_SCROLL_STAR_IDENTIFY },
		{ TV_SCROLL, SV_SCROLL_LIGHT },

		{ TV_POTION, SV_POTION_RES_STR },
		{ TV_POTION, SV_POTION_RES_INT },
		{ TV_POTION, SV_POTION_RES_WIS },
		{ TV_POTION, SV_POTION_RES_DEX },

		{ TV_POTION, SV_POTION_RES_CON },
		{ TV_POTION, SV_POTION_RES_CHR },
		{ TV_SCROLL, SV_SCROLL_ENCHANT_ARMOR },
		{ TV_SCROLL, SV_SCROLL_ENCHANT_ARMOR },

		{ TV_SCROLL, SV_SCROLL_RECHARGING },
		{ TV_SCROLL, SV_SCROLL_PHASE_DOOR },
		{ TV_SCROLL, SV_SCROLL_ENCHANT_WEAPON_TO_HIT },
		{ TV_SCROLL, SV_SCROLL_ENCHANT_WEAPON_TO_DAM },

	},

	{
		/* Magic-User store */
		{ TV_RING, SV_RING_PROTECTION },
		{ TV_RING, SV_RING_LEVITATION_FALL },
		{ TV_RING, SV_RING_PROTECTION },
		{ TV_RING, SV_RING_RESIST_FIRE },

		{ TV_RING, SV_RING_RESIST_COLD },
		{ TV_AMULET, SV_AMULET_CHARISMA },
		{ TV_RING, SV_RING_WARNING },
		{ TV_AMULET, SV_AMULET_RESIST_ACID },

		{ TV_AMULET, SV_AMULET_SEARCHING },
		{ TV_WAND, SV_WAND_SLOW_MONSTER },
		{ TV_WAND, SV_WAND_CONFUSE_MONSTER },
		{ TV_WAND, SV_WAND_SLEEP_MONSTER },

		{ TV_WAND, SV_WAND_MAGIC_MISSILE },
		{ TV_WAND, SV_WAND_STINKING_CLOUD },
		{ TV_WAND, SV_WAND_WONDER },
		{ TV_WAND, SV_WAND_DISARMING },

		{ TV_STAFF, SV_STAFF_LITE },
		{ TV_STAFF, SV_STAFF_MAPPING },
		{ TV_STAFF, SV_STAFF_DETECT_TRAP },
		{ TV_STAFF, SV_STAFF_DETECT_DOOR },

		{ TV_STAFF, SV_STAFF_DETECT_GOLD },
		{ TV_STAFF, SV_STAFF_DETECT_ITEM },
		{ TV_STAFF, SV_STAFF_DETECT_INVIS },
		{ TV_STAFF, SV_STAFF_DETECT_EVIL },

		{ TV_STAFF, SV_STAFF_TELEPORTATION },
		{ TV_STAFF, SV_STAFF_TELEPORTATION },
		{ TV_STAFF, SV_STAFF_TELEPORTATION },
		{ TV_STAFF, SV_STAFF_TELEPORTATION },

		{ TV_STAFF, SV_STAFF_IDENTIFY },
		{ TV_STAFF, SV_STAFF_IDENTIFY },
		{ TV_STAFF, SV_STAFF_IDENTIFY },

		{ TV_STAFF, SV_STAFF_IDENTIFY },
		{ TV_STAFF, SV_STAFF_REMOVE_CURSE },
		{ TV_STAFF, SV_STAFF_CURE_LIGHT },
		{ TV_STAFF, SV_STAFF_PROBING },

		{ TV_FIGURINE, 0 },

		{ TV_SORCERY_BOOK, 0 },
		{ TV_SORCERY_BOOK, 0 },
		{ TV_SORCERY_BOOK, 1 },
		{ TV_SORCERY_BOOK, 1 },

		{ TV_ARCANE_BOOK, 0 },
		{ TV_ARCANE_BOOK, 0 },
		{ TV_ARCANE_BOOK, 1 },
		{ TV_ARCANE_BOOK, 1 },

		{ TV_ARCANE_BOOK, 2 },
		{ TV_ARCANE_BOOK, 2 },
		{ TV_ARCANE_BOOK, 3 },
		{ TV_ARCANE_BOOK, 3 },
	},

	{
		/* Black Market (unused) */
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 }
	},

	{
		/* Home (unused) */
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 }
	},

	{
		/* Bookstore */
		{ TV_SORCERY_BOOK, 0 },
		{ TV_SORCERY_BOOK, 0 },
		{ TV_SORCERY_BOOK, 1 },
		{ TV_SORCERY_BOOK, 1 },

		{ TV_NATURE_BOOK, 0 },
		{ TV_NATURE_BOOK, 0 },
		{ TV_NATURE_BOOK, 1 },
		{ TV_NATURE_BOOK, 1 },

		{ TV_CHAOS_BOOK, 0 },
		{ TV_CHAOS_BOOK, 0 },
		{ TV_CHAOS_BOOK, 1 },
		{ TV_CHAOS_BOOK, 1 },

		{ TV_DEATH_BOOK, 0 },
		{ TV_DEATH_BOOK, 0 },
		{ TV_DEATH_BOOK, 1 },
		{ TV_DEATH_BOOK, 1 },

		{ TV_TRUMP_BOOK, 0 },
		{ TV_TRUMP_BOOK, 0 },
		{ TV_TRUMP_BOOK, 1 },
		{ TV_TRUMP_BOOK, 1 },

		{ TV_ARCANE_BOOK, 0 },
		{ TV_ARCANE_BOOK, 1 },
		{ TV_ARCANE_BOOK, 2 },
		{ TV_ARCANE_BOOK, 3 },

		{ TV_CRAFT_BOOK, 0 },
		{ TV_CRAFT_BOOK, 0 },
		{ TV_CRAFT_BOOK, 1 },
		{ TV_CRAFT_BOOK, 1 },

		{ TV_DEMON_BOOK, 0 },
		{ TV_DEMON_BOOK, 0 },
		{ TV_DEMON_BOOK, 1 },
		{ TV_DEMON_BOOK, 1 },

		{ TV_MUSIC_BOOK, 0 },
		{ TV_MUSIC_BOOK, 0 },
		{ TV_MUSIC_BOOK, 1 },
		{ TV_MUSIC_BOOK, 1 },

		{ TV_HEX_BOOK, 0 },
		{ TV_HEX_BOOK, 0 },
		{ TV_HEX_BOOK, 1 },
		{ TV_HEX_BOOK, 1 },
	},

	{
		/* Museum (unused) */
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 },
		{ TV_NONE, 0 }
	}
};
