#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xlib.h>
#include "./wm.h"

void configureWindow(WindowManager* wm, XConfigureRequestEvent event);
void mapWindow(WindowManager* wm, XMapRequestEvent event);

#endif
