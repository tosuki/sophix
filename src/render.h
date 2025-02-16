#ifndef MAPPER_H
#define MAPPER_H

#include <X11/Xlib.h>
#include "window_manager.h"

void mapWindow(WindowManager* wm, XMapRequestEvent ev);
void unmapWindow(WindowManager* wm, XUnmapEvent ev);
void configureWindow(WindowManager* wm, XConfigureRequestEvent ev);

#endif
