#ifndef MAPPER_H
#define MAPPER_H

#include <X11/Xlib.h>
#include "window_manager.h"

void map_window(WindowManager* wm, XMapRequestEvent ev);
void unmap_window(WindowManager* wm, XUnmapEvent ev);
void configure_window(WindowManager* wm, XConfigureRequestEvent ev);

#endif
