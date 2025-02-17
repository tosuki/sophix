#include <X11/Xlib.h>
#include <stdio.h>

#include "render.h"
#include "window_manager.h"
#include "window_collection.h"

#define WINDOW_FRAME_BACKGROUND 0x000000
#define WINDOW_FRAME_BORDER_WIDTH 3
#define WINDOW_FRAME_BORDER_COLOR 0xffffff

void frame_window(WindowManager *wm, Window window) {
    XWindowAttributes window_attributes;

    XGetWindowAttributes(wm->display, window, &window_attributes);
    Window frame = XCreateSimpleWindow(
            wm->display,
            wm->root,
            50,
            50,
            //window_attributes.x,
            //window_attributes.y,
            window_attributes.width,
            window_attributes.height,
            WINDOW_FRAME_BORDER_WIDTH,
            WINDOW_FRAME_BORDER_COLOR,
            WINDOW_FRAME_BACKGROUND
    );
    
    XAddToSaveSet(wm->display, window);
    XReparentWindow(wm->display, window, frame, 0, 0);
    window_collection_add(wm->childs, window, frame);
    XMapWindow(wm->display, frame);
    XMapWindow(wm->display, window);
}

void map_window(WindowManager *wm, XMapRequestEvent ev) {
    printf("%li is being mapped\n", ev.window);
    frame_window(wm, ev.window);
    wm->focused_window = ev.window;
}

void unmap_window(WindowManager *wm, XUnmapEvent ev) {

}

void configure_window(WindowManager *wm, XConfigureRequestEvent ev) {
    XWindowChanges window_attributes;

    window_attributes.height = ev.height;
    window_attributes.width = ev.width;
    window_attributes.border_width = ev.border_width;
    window_attributes.sibling = ev.above;
    window_attributes.x = ev.x;
    window_attributes.y = ev.y;
    window_attributes.stack_mode = ev.detail;

    WindowCollectionNode *frame = window_collection_get(wm->childs, ev.window);

    if (frame != NULL) {
        XConfigureWindow(wm->display, frame->frame, ev.value_mask, &window_attributes);
    } else {
        XConfigureWindow(wm->display, ev.window, ev.value_mask, &window_attributes);
    }
}

