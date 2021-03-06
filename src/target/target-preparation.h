#pragma once

#include "system/angband.h"

typedef struct pos_list pos_list;

bool target_able(player_type *creature_ptr, MONSTER_IDX m_idx);
void target_set_prepare(player_type *creature_ptr, BIT_FLAGS mode);
void target_sensing_monsters_prepare(player_type *creature_ptr, pos_list *plist);
