#ifndef WINDOW_H
#define WINDOW_H

#include "window_manager.h"
#include "window_collection.h"

void kill_window(WindowManager *wm, Window window);
void open_window(WindowManager *wm, char* executable);

#endif
