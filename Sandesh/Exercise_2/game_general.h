#pragma once
#ifndef GAME_GENERAL_H_INCLUDED
#define GAME_GENERAL_H_INCLUDED
/* ^^ these are the include guards */

#ifndef __cplusplus
#include <stdbool.h>
#endif

/* Prototypes for the functions */
/* Sums two ints */
extern void must_init(bool test, const char* description);
extern int between(int lo, int hi);
extern float between_f(float lo, float hi);
extern bool collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

#endif
