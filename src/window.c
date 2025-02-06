#include <X11/Xlib.h>

#include "./window.h"
#include "./wm.h"

void configureWindow(WindowManager *wm, XConfigureRequestEvent event) {
    XWindowChanges windowProperties;

    windowProperties.height = event.height;
    windowProperties.width = event.width;
    windowProperties.border_width = event.border_width;
    windowProperties.x = event.x;
    windowProperties.y = event.y;
    windowProperties.sibling = event.above;
    windowProperties.stack_mode = event.detail;

    XConfigureWindow(wm->display, event.window, event.value_mask, &windowProperties);
}

void frameWindow(WindowManager *wm, Window* window) {
    //to do
}

void mapWindow(WindowManager *wm, XMapRequestEvent event) {
    frameWindow(wm, &event.window);
    XMapWindow(wm->display, event.window);
}
