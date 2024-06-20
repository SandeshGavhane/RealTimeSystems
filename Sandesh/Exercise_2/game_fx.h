#pragma once


#ifndef GAME_FX_H_INCLUDED
#define GAME_FX_H_INCLUDED

typedef struct FX
{
	int x, y;
	int frame;
	bool spark;
	bool used;
} FX;

#define FX_N 128
FX fx[FX_N];

void fx_init();
void fx_add(bool spark, int x, int y);
void fx_update();
void fx_draw();

#endif
