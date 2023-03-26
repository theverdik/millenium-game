#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>

#include "entity.h"

void renderer_clear(Color color);
void renderer_render_rec(Entity *entity);
void renderer_render_texture_rec(Entity *entity, Texture2D *texture);

#endif // RENDERER_H
