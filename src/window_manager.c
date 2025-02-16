#include <X11/X.h>
#include <X11/Xlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "window_manager.h"

void window_manager_run(WindowManager* wm) {
    /** 
     *Those two flag will tell the xorg server to send us the events that are related to changes on
     the windows under us in the tree (childs)
     * **/
    XSelectInput(wm->display, wm->root, SubstructureNotifyMask | SubstructureRedirectMask);
    XSync(wm->display, False);

    XEvent event;

    for (;;) {
        XNextEvent(wm->display, &event);

        switch (event.type) {
            default:
                printf("Event %d dispatched\n", event.type);
                break;
        }

        XSync(wm->display, False);//apply channges xD
    }
}

WindowManager *create_window_manager() {
    WindowManager* wm = malloc(sizeof(WindowManager));

    if (wm == NULL) {
        puts("Failed to allocate memory to the window manager struct");
        exit(1);
    }

    Display* display = XOpenDisplay(NULL);

    if (display == NULL) {
        return NULL;
    }
    
    wm->display = display;
    wm->root = DefaultRootWindow(wm->display);

    return wm;
}

void destroy_window_manager(WindowManager* wm) {
    XCloseDisplay(wm->display);
    free(wm);
}
