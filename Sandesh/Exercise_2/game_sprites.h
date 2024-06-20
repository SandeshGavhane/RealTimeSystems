#pragma once
#ifndef GAME_SPRITES_H_INCLUDED
#define GAME_SPRITES_H_INCLUDED
/* ^^ these are the include guards */

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include<allegro5/allegro5.h>

#define SHIP_W 12
#define SHIP_H 13

#define SHIP_SHOT_W 2
#define SHIP_SHOT_H 9

#define LIFE_W 6
#define LIFE_H 6

#define ALIEN_SHOT_W 4
#define ALIEN_SHOT_H 4

#define EXPLOSION_FRAMES 4
#define SPARKS_FRAMES 3




typedef struct SPRITES
{
	ALLEGRO_BITMAP* _sheet;

	ALLEGRO_BITMAP* ship;
	ALLEGRO_BITMAP* ship_shot[2];
	ALLEGRO_BITMAP* life;

	ALLEGRO_BITMAP* alien[3];
	ALLEGRO_BITMAP* alien_shot;


	ALLEGRO_BITMAP* explosion[EXPLOSION_FRAMES];
	ALLEGRO_BITMAP* sparks[SPARKS_FRAMES];

	ALLEGRO_BITMAP* powerup[4];

} SPRITES;

SPRITES sprites;

/* Prototypes for the functions */

ALLEGRO_BITMAP* sprite_grab(int x, int y, int w, int h);
void sprites_init();
void sprites_deinit();

#endif

