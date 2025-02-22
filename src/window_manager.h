#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "window_collection.h"
#include <X11/Xlib.h>


/**
 * Modes:
 *      insert mode = the input is ignored and sent to the selected child window if selected
 *      command mode = the input is heard and handled by the window manager(keybinds for example)
 *      resize mode = Resize the selected window
 *      move mode = Move the selected window
 * **/
#define INSERT_MODE 0
#define COMMAND_MODE 1
#define RESIZE_MODE 2
#define MOVE_MODE 3

typedef unsigned int CommandMode;

typedef struct WindowManager {
    Display* display;
    Window root;

    unsigned int mod_key;
    Window focused_window;
    WindowCollection* childs;
    CommandMode mode;
} WindowManager;

void window_manager_run(WindowManager *wm);

WindowManager *create_window_manager();
void destroy_window_manager(WindowManager* wm);

#endif
