#pragma once

#ifndef GAME_SHOT_H_INCLUDED
#define GAME_SHOT_H_INCLUDED

#ifndef __cplusplus
#include <stdbool.h>
#endif

typedef struct SHOT
{
	int x, y, dx, dy;
	int frame;
	bool ship;
	bool used;
} SHOT;

#define SHOTS_N 128
SHOT shots[SHOTS_N];

void shots_init();
bool shots_add(bool ship, bool straight, int x, int y);
void shots_update();
bool shots_collide(bool ship, int x, int y, int w, int h);
void shots_draw();

#endif
