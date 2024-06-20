#include<allegro5/allegro5.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_image.h>
#include "game_alien.h"
#include "game_audio.h"
#include "game_display.h"
#include "game_general.h"
#include "game_fx.h"
#include "game_keyboard.h"
#include "game_general.h"
#include "game_ship.h"
#include "game_shot.h"
#include "game_sprites.h"
#include "game_star.h"

void stars_init()
{
	for (int i = 0; i < STARS_N; i++)
	{
		stars[i].y = between_f(0, BUFFER_H);
		stars[i].speed = between_f(0.1, 1);
	}
}

void stars_update()
{
	for (int i = 0; i < STARS_N; i++)
	{
		stars[i].y += stars[i].speed;
		if (stars[i].y >= BUFFER_H)
		{
			stars[i].y = 0;
			stars[i].speed = between_f(0.1, 1);
		}
	}
}

void stars_draw()
{
	float star_x = 1.5;
	for (int i = 0; i < STARS_N; i++)
	{
		float l = stars[i].speed * 0.8;
		al_draw_pixel(star_x, stars[i].y, al_map_rgb_f(l, l, l));
		star_x += 2;
	}
}
