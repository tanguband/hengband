#pragma once

#include "system/angband.h"

extern FILE *saving_savefile;
extern byte save_xor_byte;
extern u32b v_stamp;
extern u32b x_stamp;

void wr_byte(byte v);
void wr_u16b(u16b v);
void wr_s16b(s16b v);
void wr_u32b(u32b v);
void wr_s32b(s32b v);
void wr_string(concptr str);
