#pragma once

#include "system/angband.h"

#define STORE_OBJ_LEVEL 5 /* Magic Level for normal stores */

#define STORE_GENERAL   0 /*!< 店舗の種類: 雑貨屋 */
#define STORE_ARMOURY   1 /*!< 店舗の種類: 防具屋 */
#define STORE_WEAPON    2 /*!< 店舗の種類: 武器屋 */
#define STORE_TEMPLE    3 /*!< 店舗の種類: 寺院 */
#define STORE_ALCHEMIST 4 /*!< 店舗の種類: 錬金術の店 */
#define STORE_MAGIC     5 /*!< 店舗の種類: 魔道具屋 */
#define STORE_BLACK     6 /*!< 店舗の種類: ブラック・マーケット */
#define STORE_HOME      7 /*!< 店舗の種類: 我が家 */
#define STORE_BOOK      8 /*!< 店舗の種類: 書店 */
#define STORE_MUSEUM    9 /*!< 店舗の種類: 博物館 */

typedef struct object_type object_type;
typedef struct store_type {
	byte type;				  /* Store type */
	byte owner;				  /* Owner index */
	byte extra;				  /* Unused for now */
	s16b insult_cur;		  /* Insult counter */
	s16b good_buy;			  /* Number of "good" buys */
	s16b bad_buy;			  /* Number of "bad" buys */
	s32b store_open;		  /* Closed until this turn */
	s32b last_visit;		  /* Last visited on this turn */
    s16b regular_num;         /* Table -- Number of entries */
    s16b regular_size;        /* Table -- Total Size of Array */
    KIND_OBJECT_IDX *regular; /* Table -- Legal regular item kinds */
    s16b table_num;           /* Table -- Number of entries */
	s16b table_size;		  /* Table -- Total Size of Array */
    KIND_OBJECT_IDX *table;   /* Table -- Legal item kinds */
	s16b stock_num;			  /* Stock -- Number of entries */
	s16b stock_size;		  /* Stock -- Total Size of Array */
	object_type *stock;		  /* Stock -- Actual stock items */
} store_type;

extern int cur_store_num;
extern store_type *st_ptr;

typedef bool (*black_market_crap_pf)(player_type *, object_type *);
typedef bool (*store_will_buy_pf)(player_type *, object_type *);
typedef void (*mass_produce_pf)(player_type *, object_type *);
void store_delete(void);
void store_create(player_type *player_ptr, KIND_OBJECT_IDX k_idx, black_market_crap_pf black_market_crap, store_will_buy_pf store_will_buy, mass_produce_pf mass_produce);
void store_item_increase(INVENTORY_IDX item, int num);
void store_item_optimize(INVENTORY_IDX item);
int store_carry(player_type *player_ptr, object_type *o_ptr);
bool store_object_similar(object_type *o_ptr, object_type *j_ptr);
