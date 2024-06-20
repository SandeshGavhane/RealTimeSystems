#include<stdio.h>
#include<stdlib.h>
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

long frames;
long score;

extern ALIEN_W[];
extern ALIEN_H[];

long score_display;
long frame_rate;
long resume_counter;
int timer_number;
bool pause = false;
bool resume = false;
bool pause_key_pressed = false;
bool f_key_pressed = false;





int main()
{
	must_init(al_init(), "allegro");
	must_init(al_install_keyboard(), "keyboard");

	ALLEGRO_TIMER* timer1 = al_create_timer(1.0 / 60.0);
	must_init(timer1, "timer1");

	ALLEGRO_TIMER* timer2 = al_create_timer(1.0 / 30.0);
	must_init(timer2, "timer2");

	ALLEGRO_TIMER* resume_timer = al_create_timer(1.0);
	must_init(resume_timer, "pause_timer");


	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	must_init(queue, "queue");

	disp_init();

	audio_init();

	must_init(al_init_image_addon(), "image");
	sprites_init();

	hud_init();

	must_init(al_init_primitives_addon(), "primitives");

	must_init(al_install_audio(), "audio");
	must_init(al_init_acodec_addon(), "audio codecs");
	must_init(al_reserve_samples(16), "reserve samples");

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer1));
	al_register_event_source(queue, al_get_timer_event_source(timer2));
	al_register_event_source(queue, al_get_timer_event_source(resume_timer));


	keyboard_init();
	fx_init();
	shots_init();
	ship_init();
	aliens_init();
	stars_init();

	frames = 0;
	score = 0;

	bool done = false;
	bool redraw = true;

	ALLEGRO_EVENT event;

	al_start_timer(timer1);
	timer_number = 1;
	frame_rate = 60;

	while (1)
	{
		al_wait_for_event(queue, &event);

		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER:
			if (pause == false && resume == false)
			{
				fx_update();
				shots_update();
				stars_update();
				ship_update();
				aliens_update();
				hud_update();
			}

			if (resume == true && pause == true)
			{
				resume_counter = resume_counter -1;
				if (resume_counter <= 0)
				{
					resume = false;
					pause = false;

				}
			}

			if (key[ALLEGRO_KEY_ESCAPE])
				done = true;

			if (key[ALLEGRO_KEY_F])
			{
				if (f_key_pressed == false)
				{
					if (timer_number == 1)
					{
						al_stop_timer(timer1);
						al_start_timer(timer2);
						timer_number = 2;
						frame_rate = 30;
					}
					else if (timer_number == 2)
					{
						al_stop_timer(timer2);
						al_start_timer(timer1);
						frame_rate = 60;
						timer_number = 1;
					}
				}
				f_key_pressed = true;
			}
			else
			{
				f_key_pressed = false;
			}

			if (key[ALLEGRO_KEY_SPACE])
			{ 
				if (pause_key_pressed == false)
				{
					if (pause == false && resume == false)
					{
						pause = true;

					}
					else if (pause == true &&  resume == false)
					{
						resume = true;
						if (timer_number == 1)
						{
							resume_counter = 160;
						}
						else if (timer_number == 2)
						{
							resume_counter = 80;
						}
					}
				}
				pause_key_pressed = true;

			}
			else
			{
				pause_key_pressed = false;
			}
			


			if (pause == false && resume == false)
			{
				redraw = true;
				frames++;
			}

			if (resume == true && pause == true)
			{
				disp_pre_draw();
				al_clear_to_color(al_map_rgb(0, 0, 0));
				hud_resume();
				disp_post_draw();
			}

			if (pause == true && resume == false)
			{
				disp_pre_draw();
				al_clear_to_color(al_map_rgb(0, 0, 0));
				hud_pause();
				disp_post_draw();
			}

			break;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		}

		if (done)
			break;

		keyboard_update(&event);

		if (redraw && al_is_event_queue_empty(queue))
		{
			disp_pre_draw();
			al_clear_to_color(al_map_rgb(0, 0, 0));

			
			stars_draw();
			aliens_draw();
			shots_draw();
			fx_draw();
			ship_draw();


			hud_draw();

			disp_post_draw();
			redraw = false;
		}

	}

	sprites_deinit();
	hud_deinit();
	audio_deinit();
	disp_deinit();
	al_destroy_timer(timer1);
	al_destroy_timer(timer2);
	al_destroy_timer(resume_timer);
	al_destroy_event_queue(queue);

	return 0;
}
