#pragma once

#include "monster-attack/monster-attack-effect.h"
#include "monster-attack/monster-attack-types.h"
#include "system/angband.h"

#define NUM_R_FLAGS_1 32
#define NUM_R_FLAGS_2 32
#define NUM_R_FLAGS_3 32
#define NUM_R_FLAGS_4 32
#define NUM_R_ABILITY_FLAGS_1 32
#define NUM_R_ABILITY_FLAGS_2 32
#define NUM_R_FLAGS_7 32
#define NUM_R_FLAGS_8 32
#define NUM_R_FLAGS_9 33
#define NUM_R_FLAGS_R 32

extern concptr r_info_blow_method[NB_RBM_TYPE + 1];
extern concptr r_info_blow_effect[NB_RBE_TYPE + 1];
extern concptr r_info_flags1[NUM_R_FLAGS_1];
extern concptr r_info_flags2[NUM_R_FLAGS_2];
extern concptr r_info_flags3[NUM_R_FLAGS_3];
extern concptr r_info_flags4[NUM_R_FLAGS_4];
extern concptr r_a_ability_flags1[NUM_R_ABILITY_FLAGS_1];
extern concptr r_a_ability_flags2[NUM_R_ABILITY_FLAGS_2];
extern concptr r_info_flags7[NUM_R_FLAGS_7];
extern concptr r_info_flags8[NUM_R_FLAGS_8];
extern concptr r_info_flags9[NUM_R_FLAGS_9];
extern concptr r_info_flagsr[NUM_R_FLAGS_R];
