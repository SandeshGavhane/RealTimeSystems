#pragma once

#ifndef GAME_AUDIO_H_INCLUDED
#define GAME_AUDIO_H_INCLUDED

ALLEGRO_SAMPLE* sample_shot;
ALLEGRO_SAMPLE* sample_explode[2];

void audio_init();

void audio_deinit();

#endif
