#include <X11/Xlib.h>
#include <stdio.h>

#include "./keyboard.h"

void dispatchKey(WindowManager* wm, char* key, unsigned int mod) {
    KeySym keySym = XStringToKeysym(key);
    KeyCode keyCode = XKeysymToKeycode(wm->display, keySym);

    XGrabKey(
        wm->display,
        keyCode,
        mod,
        wm->rootWindow,
        False,
        GrabModeAsync,
        GrabModeAsync
    );
}

void dispatchKeyboardEvents(WindowManager* wm) {
    dispatchKey(wm, "q", ShiftMask);
}
