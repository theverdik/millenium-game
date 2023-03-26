#include <raylib.h>

#include <stdlib.h>

#include "window.h"

bool already_exists = false;

Window *window_init(int32_t width, int32_t height, const char *title)
{
	Window *window = malloc(sizeof(Window));

	window->width = width;
	window->height = height;
	window->title = title;
	window->background = BLACK;

	if (!already_exists) {
		InitWindow(width, height, title);
		already_exists = true;
	}

	return window;
}

void window_update(Window *window)
{
	if (IsKeyPressed(KEY_F11))
		ToggleFullscreen();

	if (IsWindowResized()) {
		window->width = GetScreenWidth();
		window->height = GetScreenHeight();
	}
}

void window_destroy(Window *window)
{
	window_close();
	free(window);
}
