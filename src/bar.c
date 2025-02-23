#include <stdio.h>
#include <X11/Xlib.h>

#include "bar.h"
#include "window_manager.h"


Window create_bar(WindowManager* wm) {
    int display_num = DefaultScreen(wm->display);

    int display_width = XDisplayWidth(wm->display, display_num);
    int display_height = XDisplayHeight(wm->display, display_num);

    wm->bar = XCreateSimpleWindow(wm->display, wm->root, 0, 0, display_width, 35, 2, 0xffffff, 0x000000);

    XMapWindow(wm->display, wm->bar);
}
