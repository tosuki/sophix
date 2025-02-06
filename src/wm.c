#include <X11/Xlib.h>
#include <malloc.h>

#include "./wm.h"
#include "./cursor.h"
#include "./keyboard.h"

#include "./lib/utils.h"

void initializeEventLoop(WindowManager* wm) {
    XEvent event;

    for(;;) {
        XNextEvent(wm->display, &event);

        switch (event.type) {
            case KeyPress:
                puts("A key got pressed lol");
                break;
            case ButtonPress:
                XAllowEvents(wm->display, ReplayPointer, CurrentTime);
                printf("Button %d pressed\n", event.xbutton.button);
                break;
            default:
                printf("Unhandled event of type %d\n", event.type);
                break;
        }

        XSync(wm->display, False);
    }
}

void setupWindowManager(WindowManager* wm) {
    XSelectInput(
        wm->display,
        wm->rootWindow,
        SubstructureNotifyMask | SubstructureRedirectMask
    );
    createCursor(wm);
    dispatchKeyboardEvents(wm);
    XSync(wm->display, False);

    initializeEventLoop(wm);
}

WindowManager* createWindowManager() {
    Display* display = XOpenDisplay(NULL);

    if (display == NULL) {
        panic("Failed to open display!");
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
