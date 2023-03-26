#ifndef PLAYER_H
#define PLAYER_H

#include "list.h"
#include "entity.h"

typedef struct {
	Entity *entity;
	Texture2D texture;
} Player;

void player_update(List *entities, Entity *player, uint32_t *lives, uint32_t *score);
void player_reposition(Entity *player);

#endif // PLAYER_H
