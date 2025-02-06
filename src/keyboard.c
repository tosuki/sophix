#include <X11/Xlib.h>
#include <stdio.h>

#include "./keyboard.h"

void dispatchKey(WindowManager* wm, Window* window, char* key, unsigned int mod) {
    KeySym keySym = XStringToKeysym(key);
    KeyCode keyCode = XKeysymToKeycode(wm->display, keySym);

    XGrabKey(
        wm->display,
        keyCode,
        mod,
        *window,
        False,
        GrabModeAsync,
        GrabModeAsync
    );
}

void dispatchGlobalKey(WindowManager* wm, char* key, unsigned int mod) {
    return dispatchKey(wm, &wm->rootWindow, "q", ShiftMask);
}

void dispatchKeyboardEvents(WindowManager* wm) {
    dispatchGlobalKey(wm, "e", ShiftMask);
}

void dispatchWindowKeyboardEvents(WindowManager* wm, Window* window) {
    dispatchKey(wm, window, "q", Mod1Mask);//Shift + q
}
