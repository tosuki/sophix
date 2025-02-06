#include "./cursor.h"
#include "./wm.h"

#include <X11/Xlib.h>
#include <X11/cursorfont.h>

void dispatchCursorButtonEvent(WindowManager *wm, Cursor *pointer, unsigned int button) {
    XGrabButton(
        wm->display,
        button,
        0,
        wm->rootWindow,
        0,
        ButtonPressMask,
        GrabModeSync,
        GrabModeAsync,
        wm->rootWindow,
        *pointer
    );
};

void createCursor(WindowManager* wm) {
    Cursor cursor = XCreateFontCursor(wm->display, XC_left_ptr);

    XDefineCursor(wm->display, wm->rootWindow, cursor);

    dispatchCursorButtonEvent(wm, &cursor, Button1);
    dispatchCursorButtonEvent(wm, &cursor, Button2);
    dispatchCursorButtonEvent(wm, &cursor, Button3);
    dispatchCursorButtonEvent(wm, &cursor, Button4);
}

