#ifndef WINDOW_H
#define WINDOW_H

#include <raylib.h>
#include <stdint.h>

#define window_should_close WindowShouldClose
#define window_close CloseWindow
#define window_is_ready IsWindowReady
#define window_is_fullscreen IsWindowFullscreen
#define window_is_hidden IsWindowHidden
#define window_is_minimized IsWindowMinimized
#define window_is_maximized IsWindowMaximized
#define window_is_focused IsWindowFocused
#define window_is_reized IsWindowResized
#define window_is_state IsWindowState
#define window_set_state SetWindowState
#define window_create_state ClearWindowState
#define window_toggle_fullscreen ToggleFullscreen
#define window_maximize MaximizeWindow
#define window_minimize MinimizeWindow
#define wiindow_restore RestoreWindow
#define window_set_icon SetWindowIcon
#define window_set_icons SetWindowIcons
#define window_set_title SetWindowTitle
#define window_set_position SetWindowPosition
#define window_set_monitor SetWindowMonitor
#define window_set_min_size SetWindowMinSize
#define window_set_size SetWindowSize
#define window_set_opacity SetWindowOpacity
#define window_get_handle GetWindowHandle
#define window_get_width GetScreenWidth
#define window_get_height GetScreenHeight
#define window_get_position GetWindowPosition
#define window_gat_scale_dpi GetWindowScaleDPI
#define window_enable_event_waiting EnableEventWaiting
#define window_disable_event_waiting DisableEventWaiting

typedef struct {
	int32_t width, height;
	const char *title;
	Color background;
} Window;

Window *window_init(int32_t width, int32_t height, const char *title);
void    window_update(Window *window);
void    window_destroy(Window *window);

#endif // WINDOW_H
