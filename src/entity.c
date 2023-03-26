#include <stdlib.h>

#include "entity.h"

Entity *entity_create(EntityType type, float x, float y, float width, float height)
{
	Entity *entity = calloc(1, sizeof(Entity));

	entity->type = type;
	entity->body.x = x;
	entity->body.y = y;
	entity->body.width = width;
	entity->body.height = height;
	entity->color = WHITE;

	return entity;
}
