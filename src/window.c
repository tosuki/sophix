#include <X11/Xlib.h>
#include <stdio.h>

#include "./window.h"
#include "./wm.h"
#include "./frame.h"
#include "./keyboard.h"


/**
 * defines the initial size of the window
 * **/
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

/**
 * This is the window that represents the decorations (borders, titlebar...)
 * This is rendered every time we receive a maprequest from the xorg
 * **/
void frameWindow(WindowManager *wm, Window* window) {
    WindowFrame frameProperties = createWindowFrame(
        3,
        0xff0000, //black color
        0xffffff
    );

    XWindowAttributes windowAttributes;

    XGetWindowAttributes(wm->display, *window, &windowAttributes);
    //draw frame

    Window frameWindow = XCreateSimpleWindow(
        wm->display,
        wm->rootWindow,
        windowAttributes.x,
        windowAttributes.y,
        windowAttributes.width,
        windowAttributes.height,
        frameProperties.borderWidth,
        frameProperties.borderColor,
        frameProperties.backgroundColor
    );

    XAddToSaveSet(wm->display, window);//save the window entity in the save set managed by x11 in case the wm crashes
    XReparentWindow(wm->display, *window, frameWindow, 0, 0);
    XMapWindow(wm->display, frameWindow);

    dispatchWindowKeyboardEvents(wm, &frameWindow);
}

void mapWindow(WindowManager *wm, XMapRequestEvent event) {
    frameWindow(wm, &event.window);
    XMapWindow(wm->display, event.window);
}
