#include <X11/X.h>
#include <X11/Xlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "window_manager.h"
#include "keybinds.h"
#include "pointer.h"
#include "render.h"
#include "window_collection.h"
#include "bar.h"

int window_manager_on_error(Display* display, XErrorEvent* ev) {
    printf("An error occurred, the error code is: %d\n", ev->error_code);

    return 0;
}

void window_manager_run(WindowManager* wm) {
    /** 
     *Those two flag will tell the xorg server to send us the events that are related to changes on
     the windows under us in the tree (childs)
     * **/
    XSelectInput(wm->display, wm->root, SubstructureNotifyMask | SubstructureRedirectMask);
    XSetErrorHandler(&window_manager_on_error);
    create_bar(wm);
    register_global_keybinds(wm);
    create_mouse_pointer(wm);
    wm->bar = create_bar(wm);
    XSync(wm->display, False);

    XEvent event;

    for (;;) {
        XNextEvent(wm->display, &event);

        switch (event.type) {
            case CreateNotify:
            case ReparentNotify:
                break;
            case KeyPress:
                handle_keydown(wm, event.xkey);
                break;
            case KeyRelease:
                break;
            case MapRequest:
                puts("A window got requested to be mapped");
                map_window(wm, event.xmaprequest);
                break;
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
    wm->mode = COMMAND_MODE;
    wm->mod_key = Mod1Mask;
    wm->root = DefaultRootWindow(wm->display);
    wm->focused_window = -1;
    wm->childs = create_window_collection();

    return wm;
}

void destroy_window_manager(WindowManager* wm) {
    XCloseDisplay(wm->display);
    free(wm);
    exit(1);
}
