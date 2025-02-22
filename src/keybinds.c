#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>

#include "window.h"
#include "keybinds.h"
#include "window_manager.h"

KeyCode get_key_code(WindowManager* wm, char *key) {
    return XKeysymToKeycode(wm->display, XStringToKeysym(key));
};

void grab_key(WindowManager* wm, Window window, char* key, unsigned int mask) {
    KeySym key_sym = XStringToKeysym(key);
    KeyCode key_code = XKeysymToKeycode(wm->display, key_sym);

    XGrabKey(wm->display, key_code, mask, window, False, GrabModeAsync, GrabModeAsync);
}

void register_global_keybinds(WindowManager* wm) {
    grab_key(wm, wm->root, "q", wm->mod_key);
    grab_key(wm, wm->root, "c", wm->mod_key);
    grab_key(wm, wm->root, "i", wm->mod_key);
}

void handle_commands(WindowManager* wm, XKeyPressedEvent ev) {
    switch (ev.keycode) {
        case 24://q //destroy window
            if (wm->focused_window == -1) {
                puts("Attempt to destroy a window, but there is no one focused at the moment");
                return;
            }
            
            kill_window(wm, wm->focused_window);

            break;
    }     
}

void handle_keydown(WindowManager *wm, XKeyPressedEvent ev) {
    switch (ev.keycode) {
        case 31://i
            puts("Changing to insert mode");
            wm->mode = INSERT_MODE;
            break;
        case 54://C
            puts("Changing to command mode");
            wm->mode = COMMAND_MODE;
            break;
    }

    switch (wm->mode) {
        case COMMAND_MODE:
            handle_commands(wm, ev);
            break;
        case INSERT_MODE:
            puts("Key pressed on insert mode");
            break;           
    }
}
