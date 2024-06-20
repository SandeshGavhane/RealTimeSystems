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
#include "game_hud.h"

extern score_display;
extern frame_rate;
extern resume_counter;
extern frames;
extern score;

void hud_init()
{
	font = al_create_builtin_font();
	must_init(font, "font");


	score_display = 0;

	frame_rate = 0;

	resume_counter = 0;
}

void hud_deinit()
{
	al_destroy_font(font);
}

void hud_update()
{
	if (frames % 2)
		return;

	for (long i = 5; i > 0; i--)
	{
		long diff = 1 << i;
		if (score_display <= (score - diff))
			score_display += diff;
	}
}

void hud_pause()
{
	al_draw_text(
		font,
		al_map_rgb_f(1, 1, 1),
		BUFFER_W / 2, BUFFER_H / 2,
		ALLEGRO_ALIGN_CENTER,
		"Game Paused"
	);
}

void hud_resume()
{
	al_draw_textf(
		font,
		al_map_rgb_f(1, 1, 1),
		BUFFER_W / 2, BUFFER_H / 2,
		ALLEGRO_ALIGN_CENTER,
		"Resuming count : %03ld",
		resume_counter / 10
	);
}

void hud_draw()
{
	al_draw_textf(
		font,
		al_map_rgb_f(1, 1, 1),
		1, 1,
		0,
		"%06ld",
		score_display
	);

	//al_draw_multiline_text(font, al_map_rgb_f(1, 1, 1), 1, 10,100,10, ALLEGRO_ALIGN_LEFT,"Up/Down/Left/Right Key to move");


	al_draw_text(
		font,
		al_map_rgb_f(1, 1, 1),
		1, 10,
		ALLEGRO_ALIGN_LEFT,
		"Up/Down/Left/Right-Move"
	);


	al_draw_text(
		font,
		al_map_rgb_f(1, 1, 1),
		1, 20,
		ALLEGRO_ALIGN_LEFT,
		"F-Toggle frameRate,Esc-Quit,X-Shoot"
	);

	al_draw_textf(
		font,
		al_map_rgb_f(1, 1, 1),
		1, 30,
		0,
		"Rate : %02ld",
		frame_rate
	);

	int spacing = LIFE_W + 1;
	for (int i = 0; i < ship.lives; i++)
		al_draw_bitmap(sprites.life, 1 + (i * spacing), 10, 0);

	if (ship.lives < 0)
		al_draw_text(
			font,
			al_map_rgb_f(1, 1, 1),
			BUFFER_W / 2, BUFFER_H / 2,
			ALLEGRO_ALIGN_CENTER,
			"G A M E  O V E R"
		);
}