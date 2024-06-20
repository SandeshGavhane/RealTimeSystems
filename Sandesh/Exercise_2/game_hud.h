
#pragma once

#ifndef GAME_HUD_H_INCLUDED
#define GAME_HUD_H_INCLUDED

ALLEGRO_FONT* font;

void hud_init();
void hud_deinit();
void hud_update();
void hud_pause();
void hud_resume();
void hud_draw();
#endif
