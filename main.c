#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/Xutil.h>

#include <stdio.h>
#include <stdlib.h>

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
    XSync(display, 0);

    XEvent event;

    for(;;) {
        XNextEvent(display, &event);
        
        switch (event.type) {
            default:
                puts("Unexpected event");
                break;
        }
        XSync(display, 0);
    }    

    XColor color;
    if (!XAllocNamedColor(display, DefaultColormap(display, DefaultScreen(display)), "#ffffff", &color, &color)) {
        fprintf(stderr, "Unable to allocate color\n");
        return 1;
    }

    XSetWindowBackground(display, root_window, color.pixel);

    Cursor cursor = XCreateFontCursor(display, XC_left_ptr);

    XDefineCursor(display, root_window, cursor);
    XSync(display, 0);

    XCloseDisplay(display);

    return 0;
}
