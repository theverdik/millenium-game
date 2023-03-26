#include <raylib.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "list.h"
#include "target.h"
#include "entity.h"
#include "player.h"
#include "renderer.h"

static Game *init(int32_t width, int32_t height, const char *title);

static void update(Game *game);
static void render(Game *game);

static void terminate(Game *game);

static Game *init(int32_t width, int32_t height, const char *title)
{
	Game *game = malloc(sizeof(Game));

	game->window = window_init(width, height, title);
	game->entities = list_create();

	game->lives = 3;
	game->score = 0;

	return game;
}

void game_run(int32_t width , int32_t height, const char *title)
{
	Game *game = init(width, height, title);
	SetTargetFPS(60);

	InitAudioDevice();
	Music yugioh = LoadMusicStream("assets/audio/yugioh.mp3");
	PlayMusicStream(yugioh);
	SetMusicVolume(yugioh, 0.75f);

	Image yugi = LoadImage("assets/textures/yugi.png");
	Image millenium = LoadImage("assets/textures/buzzle.png");

	Texture yugi_tex = LoadTextureFromImage(yugi);
	Texture millenium_tex = LoadTextureFromImage(millenium);

	UnloadImage(yugi);
	UnloadImage(millenium);

	game->player.entity = entity_create(ENTITY_PLAYER, 0, 720 - 135, 125.0f, 125.0f);

	list_add(game->entities, game->player.entity, sizeof(Entity));
	game->player.texture = yugi_tex;

	game->target.entity = entity_create(ENTITY_TARGET, (1280 >> 1) - 55.0f / 2, 10.0f, 55.0f, 55.0f);
	list_add(game->entities, game->target.entity, sizeof(Entity));
	game->target.texture = millenium_tex;

	while (!window_should_close()) {
		UpdateMusicStream(yugioh);

		if (game->lives == 0)
			break;

		update(game);
		render(game);
	}

	UnloadTexture(yugi_tex);
	UnloadTexture(millenium_tex);

	StopMusicStream(yugioh);
	UnloadMusicStream(yugioh);

	CloseAudioDevice();
	terminate(game);
}

static void update(Game *game)
{
	window_update(game->window);
	player_update(game->entities, game->player.entity, &game->lives, &game->score);

	list_remove_marked(game->entities);
}

float time = 0.0f;

static void render(Game *game)
{
	BeginDrawing();
	ClearBackground(game->window->background);

	if (time > 8.9f) {
		renderer_render_texture_rec(game->player.entity, &game->player.texture);
		renderer_render_texture_rec(game->target.entity, &game->target.texture);

		char lives_text[9] = {0};
		sprintf(lives_text, "Lives: %d", game->lives);

		char *score_text = calloc(strlen("Score: ") + (uint32_t)(log(game->score) + 1), sizeof(char));
		sprintf(score_text, "Score: %d", game->score);

		DrawText(lives_text, 0, 0, 50, WHITE);
		DrawText(score_text, 0, 50, 50, WHITE);

		free(score_text);
	}
	else {
		time += GetFrameTime();

		float color_mul;
		if (time < 6.0f)
			color_mul = time / 6.0f;
		else
		 	color_mul = 1.0f;
		DrawText("Get Ready...", 640 - (MeasureText("Get Ready...", 100) >> 1), 310, 100, (Color) {255, 255, 255, color_mul * 255});
	}
	
	EndDrawing();
}

static void terminate(Game *game)
{
	window_destroy(game->window);
	list_free(game->entities);
	free(game);
}
