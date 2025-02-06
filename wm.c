#include <X11/Xlib.h>
#include <malloc.h>

#include "./wm.h"
#include "./error.h"

WindowManager* createWindowManager() {
    Display* display = XOpenDisplay(NULL);

    if (display == NULL) {
        panic("Failed to open display");
    }


    WindowManager* windowManager = malloc(sizeof(WindowManager));

    windowManager->display = display;
    windowManager->rootWindow = DefaultRootWindow(display);

    return windowManager;
}

void closeWindowManager(WindowManager* wm) {
    XCloseDisplay(wm->display);
    free(wm);
}
