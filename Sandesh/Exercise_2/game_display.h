#pragma once
#ifndef GAME_DISPLAY_H_INCLUDED
#define GAME_DISPLAY_H_INCLUDED
/* ^^ these are the include guards */

#ifndef __cplusplus
#include <stdbool.h>
#endif

#define BUFFER_W 320
#define BUFFER_H 240

#define DISP_SCALE 5
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

ALLEGRO_DISPLAY* disp;
ALLEGRO_BITMAP* buffer;

/* Prototypes for the functions */

void disp_init();
void disp_deinit();
void disp_pre_draw();
void disp_post_draw();

#endif
