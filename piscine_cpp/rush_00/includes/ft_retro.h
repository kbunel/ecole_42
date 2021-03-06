#ifndef FT_RETRO_H
#define FT_RETRO_H

#define MAX_MISSILES_IN_SLOT 50
#define ENEMIES_MISSILES 10
#define NB_ENEMIES 50
#define NB_ASTEROIDS 200
#define NB_MENUSTAR 400
#define SIZE_INTERFACE 5
#define FPS 120
#define MIN_ENEMIES_FREQUENCY 700
#define LIFE_START 3

#include <ncurses.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

enum {
	PLAYER,
	ENEMY,
	MISSILE_PLAYER,
	MISSILE_ENEMY,
	WALL,
	ASTEROID
};

#endif
