#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include <stdint.h>

#include "list.h"
#include "window.h"
#include "entity.h"
#include "player.h"
#include "target.h"

typedef struct {
	Window *window;
	List *entities;

	Player player;
	Target target;

	uint32_t lives;
	uint32_t score;

	float delta_time;
} Game;

void game_run(int32_t width , int32_t height, const char *title);

#endif // GAME_H
