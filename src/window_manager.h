#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <X11/Xlib.h>

typedef struct WindowManager {
    Display* display;
    Window root;
} WindowManager;

void window_manager_run(WindowManager *wm);

WindowManager *create_window_manager();
void destroy_window_manager(WindowManager* wm);

#endif
