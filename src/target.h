#ifndef TARGET_H
#define TARGET_H

#include <raylib.h>

#include "list.h"
#include "entity.h"

typedef struct {
	Entity *entity;
	Texture2D texture;
} Target;

void target_update(List *entities, Entity *target);

#endif // TARGET_H
