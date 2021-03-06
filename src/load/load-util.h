#pragma once

#include "system/angband.h"

extern FILE *loading_savefile;
extern byte load_xor_byte;
extern u32b v_check;
extern u32b x_check;
extern byte kanji_code;

void load_note(concptr msg);
byte sf_get(void);
void rd_byte(byte *ip);
void rd_u16b(u16b *ip);
void rd_s16b(s16b *ip);
void rd_u32b(u32b *ip);
void rd_s32b(s32b *ip);
void rd_string(char *str, int max);
void strip_bytes(int n);
