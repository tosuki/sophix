#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <X11/Xlib.h>
#include "./wm.h"

void dispatchKeyboardEvents(WindowManager* wm);
void dispatchWindowKeyboardEvents(WindowManager* wm, Window* window);

#endif