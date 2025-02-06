#include "./cursor.h"

#include <X11/Xlib.h>
#include <X11/cursorfont.h>

void register_cursor_button(Display *display, Window *root_window, Cursor *pointer, unsigned int button) {
    XGrabButton(
        display,
        button,
        0,
        *root_window,
        0,
        ButtonPressMask,
        GrabModeSync,
        GrabModeAsync,
        *root_window,
        *pointer
    );
};

void create_cursor(Display *display, Window *root_window) {
    Cursor cursor = XCreateFontCursor(display, XC_left_ptr);

    XDefineCursor(display, *root_window, cursor);

    register_cursor_button(display, root_window, &cursor, Button1);
    register_cursor_button(display, root_window, &cursor, Button2);
    register_cursor_button(display, root_window, &cursor, Button3);
    register_cursor_button(display, root_window, &cursor, Button4);
}

