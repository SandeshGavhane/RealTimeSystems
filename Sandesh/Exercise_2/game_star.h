#pragma once
#ifndef GAME_STAR_H_INCLUDED
#define GAME_STAR_H_INCLUDED

#include "game_display.h"
typedef struct STAR
{
	float y;
	float speed;
} STAR;

#define STARS_N ((BUFFER_W / 2) - 1)
STAR stars[STARS_N];

#endif
