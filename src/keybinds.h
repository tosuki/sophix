#ifndef KEYBINDS_H
#define KEYBINDS_H

#include "window_manager.h"
#include <X11/Xlib.h>

void handle_keydown(WindowManager* wm, XKeyPressedEvent ev);
void register_global_keybinds(WindowManager* wm);

#endif
