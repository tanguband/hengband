﻿/*!
 * @file grid.h
 * @brief ダンジョンの生成処理の基幹部分ヘッダーファイル
 * @date 2014/08/15
 * @details
 * Purpose: header file for grid.c, used only in dungeon generation
 * files (generate.c, rooms.c)
 * @author
 * Copyright (c) 1989 James E. Wilson, Robert A. Koeneke
 * This software may be copied and distributed for educational, research, and
 * not for profit purposes provided that this copyright and statement are
 * included in all such copies.
 */

/* Macros */

#define set_cave_feat(Y,X,F)    (grid_array[(Y)][(X)].feat = (F))
#define add_cave_info(Y,X,I)    (grid_array[(Y)][(X)].info |= (I))

/* This should not be used */
/*#define set_cave_info(Y,X,I)    (grid_array[(Y)][(X)].info = (I)) */

/*!
 * @brief 指定座標が瓦礫かどうかを返す
 * @param Y 指定Y座標
 * @param X 指定X座標
 * @return 瓦礫ならばTRUE
 */
#define place_rubble(Y,X)       set_cave_feat(Y,X,feat_rubble)

/*!
 * @brief 指定座標が上り階段かどうかを返す
 * @param Y 指定Y座標
 * @param X 指定X座標
 * @return 上り階段ならばTRUE
 */
#define place_up_stairs(Y,X)    set_cave_feat(Y,X,feat_up_stair)

/*!
 * @brief 指定座標が下り階段かどうかを返す
 * @param Y 指定Y座標
 * @param X 指定X座標
 * @return 下り階段ならばTRUE
 */
#define place_down_stairs(Y,X)  set_cave_feat(Y,X,feat_down_stair)

/*!
 * @brief 指定座標がFLOOR属性を持ったマスかどうかを返す
 * @param Y 指定Y座標
 * @param X 指定X座標
 * @return FLOOR属性を持っているならばTRUE
 */
#define is_floor_bold(Y,X) (grid_array[Y][X].info & CAVE_FLOOR)
#define is_extra_bold(Y,X) (grid_array[Y][X].info & CAVE_EXTRA)

#define is_inner_bold(Y,X) (grid_array[Y][X].info & CAVE_INNER)
#define is_outer_bold(Y,X) (grid_array[Y][X].info & CAVE_OUTER)
#define is_solid_bold(Y,X) (grid_array[Y][X].info & CAVE_SOLID)

#define is_floor_grid(C) ((C)->info & CAVE_FLOOR)
#define is_extra_grid(C) ((C)->info & CAVE_EXTRA)
#define is_inner_grid(C) ((C)->info & CAVE_INNER)
#define is_outer_grid(C) ((C)->info & CAVE_OUTER)
#define is_solid_grid(C) ((C)->info & CAVE_SOLID)

#define place_floor_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_ground_type[randint0(100)]); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_FLOOR); \
	delete_monster(Y, X); \
}

#define place_floor_grid(C) \
{ \
	(C)->feat = feat_ground_type[randint0(100)]; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_FLOOR; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_extra_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_wall_type[randint0(100)]); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_EXTRA); \
	delete_monster(Y, X); \
}

#define place_extra_grid(C) \
{ \
	(C)->feat = feat_wall_type[randint0(100)]; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_EXTRA; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_extra_perm_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_permanent); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_EXTRA); \
	delete_monster(Y, X); \
}

#define place_extra_perm_grid(C) \
{ \
	(C)->feat = feat_permanent; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_EXTRA; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_extra_noperm_bold(Y, X) \
{ \
	feature_type *_f_ptr; \
	set_cave_feat(Y,X,feat_wall_type[randint0(100)]); \
	_f_ptr = &f_info[grid_array[Y][X].feat]; \
	if (permanent_wall(_f_ptr)) grid_array[Y][X].feat = feat_state(grid_array[Y][X].feat, FF_UNPERM); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_EXTRA); \
	delete_monster(Y, X); \
}

#define place_inner_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_wall_inner); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_INNER); \
	delete_monster(Y, X); \
}

#define place_inner_grid(C) \
{ \
	(C)->feat = feat_wall_inner; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_INNER; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_inner_perm_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_permanent); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_INNER); \
	delete_monster(Y, X); \
}

#define place_inner_perm_grid(C) \
{ \
	(C)->feat = feat_permanent; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_INNER; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_outer_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_wall_outer); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_OUTER); \
	delete_monster(Y, X); \
}

#define place_outer_grid(C) \
{ \
	(C)->feat = feat_wall_outer; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_OUTER; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_outer_perm_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_permanent); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_OUTER); \
	delete_monster(Y, X); \
}

#define place_outer_perm_grid(C) \
{ \
	(C)->feat = feat_permanent; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_OUTER; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_outer_noperm_bold(Y, X) \
{ \
	feature_type *_f_ptr = &f_info[feat_wall_outer]; \
	if (permanent_wall(_f_ptr)) set_cave_feat(Y, X, (s16b)feat_state(feat_wall_outer, FF_UNPERM)); \
	else set_cave_feat(Y,X,feat_wall_outer); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,(CAVE_OUTER | CAVE_VAULT)); \
	delete_monster(Y, X); \
}

#define place_outer_noperm_grid(C) \
{ \
	feature_type *_f_ptr = &f_info[feat_wall_outer]; \
	if (permanent_wall(_f_ptr)) (C)->feat = (s16b)feat_state(feat_wall_outer, FF_UNPERM); \
	else (C)->feat = feat_wall_outer; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= (CAVE_OUTER | CAVE_VAULT); \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_solid_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_wall_solid); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_SOLID); \
	delete_monster(Y, X); \
}

#define place_solid_grid(C) \
{ \
	(C)->feat = feat_wall_solid; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_SOLID; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_solid_perm_bold(Y, X) \
{ \
	set_cave_feat(Y,X,feat_permanent); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_SOLID); \
	delete_monster(Y, X); \
}

#define place_solid_perm_grid(C) \
{ \
	(C)->feat = feat_permanent; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_SOLID; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}

#define place_solid_noperm_bold(Y, X) \
{ \
	feature_type *_f_ptr = &f_info[feat_wall_solid]; \
	if ((grid_array[Y][X].info & CAVE_VAULT) && permanent_wall(_f_ptr)) \
		set_cave_feat(Y, X, feat_state(feat_wall_solid, FF_UNPERM)); \
	else set_cave_feat(Y,X,feat_wall_solid); \
	grid_array[Y][X].info &= ~(CAVE_MASK); \
	add_cave_info(Y,X,CAVE_SOLID); \
	delete_monster(Y, X); \
}

#define place_solid_noperm_grid(C) \
{ \
	feature_type *_f_ptr = &f_info[feat_wall_solid]; \
	if (((C)->info & CAVE_VAULT) && permanent_wall(_f_ptr)) \
		(C)->feat = feat_state(feat_wall_solid, FF_UNPERM); \
	else (C)->feat = feat_wall_solid; \
	(C)->info &= ~(CAVE_MASK); \
	(C)->info |= CAVE_SOLID; \
	if ((C)->m_idx) delete_monster_idx((C)->m_idx); \
}


/* Externs */

extern bool new_player_spot(void);

extern void place_random_stairs(POSITION y, POSITION x);
extern void place_random_door(POSITION y, POSITION x, bool room);
extern void place_closed_door(POSITION y, POSITION x, int type);
extern void add_door(POSITION x, POSITION y);
extern void place_secret_door(POSITION y, POSITION x, int type);
extern void place_locked_door(POSITION y, POSITION x);
extern void try_door(POSITION y, POSITION x);
extern void place_floor(POSITION x1, POSITION x2, POSITION y1, POSITION y2, bool light);
extern void place_room(POSITION x1, POSITION x2, POSITION y1, POSITION y2, bool light);
extern void vault_monsters(POSITION y1, POSITION x1, int num);
extern void vault_objects(POSITION y, POSITION x, int num);
extern void vault_trap_aux(POSITION y, POSITION x, POSITION yd, POSITION xd);
extern void vault_traps(POSITION y, POSITION x, POSITION yd, POSITION xd, int num);

extern bool get_is_floor(POSITION x, POSITION y);
extern void set_floor(POSITION x, POSITION y);
extern void place_bound_perm_wall(grid_type *g_ptr);

extern bool is_known_trap(grid_type *g_ptr);
extern bool is_hidden_door(grid_type *g_ptr);
extern bool is_mirror_grid(grid_type *g_ptr);
extern bool is_glyph_grid(grid_type *g_ptr);
extern bool is_explosive_rune_grid(grid_type *g_ptr);