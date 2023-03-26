#include "renderer.h"
#include <raylib.h>

void renderer_clear(Color color)
{
	ClearBackground(color);
}

void renderer_render_rec(Entity *entity)
{
	DrawRectangleRec(entity->body, entity->color);
}

void renderer_render_texture_rec(Entity *entity, Texture2D *texture)
{
	DrawTexturePro(*texture, (Rectangle) {0, 0, texture->width, texture->height}, entity->body, (Vector2) {0}, 0.0f, WHITE);
}