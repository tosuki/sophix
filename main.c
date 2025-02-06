#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <stdio.h>
#include <stdlib.h>

#include "./cursor.h"

void panic(char *message) {
    puts(message);
    exit(1);
}

Display *display;
Window root_window;

int main() {
    display = XOpenDisplay(NULL);

    if (display == NULL) {
        panic("Unable to open display");
    }

    root_window = DefaultRootWindow(display);

    XSelectInput(display, root_window, SubstructureNotifyMask | SubstructureRedirectMask);
    create_cursor(display, &root_window);
    XSync(display, 0);

    XEvent event;

    for(;;) {
        XNextEvent(display, &event);
        
        switch (event.type) {
            case ButtonPress:
                XAllowEvents(display, ReplayPointer, CurrentTime);
                XSync(display, 0);
                puts("Button pressed");
                break;
            default:
                puts("Unexpected event");
                break;
        }
        XSync(display, 0);
    }    

    XCloseDisplay(display);

    return 0;
}
