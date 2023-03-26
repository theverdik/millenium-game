#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>

#include <stdint.h>
#include <stddef.h>

typedef enum {
	ENTITY_PLAYER,
	ENTITY_TARGET
} EntityType;

typedef struct {
	EntityType type;

	Rectangle body;
	Vector2 velocity;
	Vector2 acceleration;
	Color color;
} Entity;

Entity *entity_create(EntityType type, float x, float y, float width, float height);

#endif // ENTITY_H
