#include "player.h"
#include "list.h"
#include <raylib.h>

float multiplier = 1.0f;

void player_update(List *entities, Entity *player, uint32_t *lives, uint32_t *score)
{
	if (IsKeyPressed(KEY_SPACE)) {
		player->velocity.y = -30.0f;
	}

	for (Node *temp = entities->head; temp != NULL; temp = temp->next) {
		if (((Entity *)temp->data)->type == ENTITY_TARGET) {
			if (CheckCollisionRecs(player->body, ((Entity *)temp->data)->body)) {
				player_reposition(player);
				multiplier += 1.0f;
				player->velocity.y = 0;
				++(*score);
			}
		}
	}

	if (player->velocity.y == 0) {
		if (player->body.x < (1280 >> 1) - player->body.width / 2)
			player->acceleration.x = 0.1f * multiplier;
		else
			player->acceleration.x = -0.1f * multiplier;
	}
	else {
		player->acceleration.x = 0.0f;
		player->velocity.x = 0.0f;
	}

	if (player->body.y + player->body.height < 0) {
		player_reposition(player);
		player->velocity.y = 0;
		--(*lives);
	}

	player->velocity.x += player->acceleration.x;
	player->velocity.y += player->acceleration.y;

	player->body.x += player->velocity.x;
	player->body.y += player->velocity.y;
}

void player_reposition(Entity *player)
{
	player->body.x = 0;
	player->body.y = 720 - (player->body.height + 10);
}
