#include "window.h"

#include <X11/Xlib.h>
#include <stdio.h>

void open_window(WindowManager *wm, char* executable) {
    printf("Attempt to open %s\n", executable);
}

void kill_window(WindowManager *wm, Window window) {
    printf("Attempt to kill %li\n", window);
}
