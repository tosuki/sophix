#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include "pointer.h"
#include "window_manager.h"

void create_mouse_pointer(WindowManager *wm) {
    Cursor cursor = XCreateFontCursor(wm->display, XC_left_ptr);
    XDefineCursor(wm->display, wm->root, cursor);
}
