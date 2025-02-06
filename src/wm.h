#ifndef WM_H
#define WM_H

#include <X11/Xlib.h>

typedef struct windowManager {
    Display *display;
    Window rootWindow;
} WindowManager;

WindowManager* createWindowManager();
void closeWindowManager(WindowManager* wm);
void setupWindowManager(WindowManager* wm);

#endif