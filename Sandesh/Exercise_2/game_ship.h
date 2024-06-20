#pragma once

#ifndef GAME_SHIP_H_INCLUDED
#define GAME_SHIP_H_INCLUDED

#define SHIP_SPEED 3
#define SHIP_MAX_X (BUFFER_W - SHIP_W)
#define SHIP_MAX_Y (BUFFER_H - SHIP_H)

typedef struct SHIP
{
	int x, y;
	int shot_timer;
	int lives;
	int respawn_timer;
	int invincible_timer;
} SHIP;
SHIP ship;

void ship_init();
void ship_update();
void ship_draw();

#endif
