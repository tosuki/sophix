#ifndef WM_H
#define WM_H

#include <X11/Xlib.h>
#include "./window_collection.h"

typedef struct windowManager {
    Display *display;
    Window rootWindow;
    WindowCollection* childWindows;
} WindowManager;

WindowManager* createWindowManager();
void closeWindowManager(WindowManager* wm);
void setupWindowManager(WindowManager* wm);

#endif