#pragma once
#ifndef GAME_KEYBOARD_H_INCLUDED
#define GAME_KEYBOARD_H_INCLUDED
/* ^^ these are the include guards */

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include<allegro5/allegro5.h>

#define KEY_SEEN 1
#define KEY_RELEASED 2
unsigned char key[ALLEGRO_KEY_MAX];

/* Prototypes for the functions */

void keyboard_update(ALLEGRO_EVENT* event);
void keyboard_init();

#endif

