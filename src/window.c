#include "window.h"

#include <X11/Xlib.h>
#include <stdio.h>

void open_window(WindowManager *wm, char* executable) {
    printf("Attempt to open %s\n", executable);
}

void kill_window(WindowManager *wm, Window window) {
    printf("Attempt to kill %li\n", window);
}

void move_window_y(WindowManager* wm, Window window, XWindowAttributes attributes, int offset) {
    XMoveResizeWindow(wm->display, window, attributes.x, attributes.y + offset, attributes.width, attributes.height);
}

void move_window_x(WindowManager* wm, Window window, XWindowAttributes attributes, int offset) {
    XMoveResizeWindow(wm->display, window, attributes.x + offset, attributes.y, attributes.width, attributes.height);
}

void move_window(WindowManager *wm, unsigned int keycode) {
    WindowCollectionNode* window_frame_node = window_collection_get(wm->childs, wm->focused_window);

    if (window_frame_node == NULL) {
        puts("Attempt to move an non-client window");
        return;
    }

    XWindowAttributes frame_attributes;

    XGetWindowAttributes(wm->display, window_frame_node->frame, &frame_attributes);
    printf("X: %d Y: %d KeyCode: %d\n", frame_attributes.x, frame_attributes.y, keycode);

    switch (keycode) {
        case 111:
            move_window_y(wm, window_frame_node->frame, frame_attributes, -5);
            break;
        case 116:
            move_window_y(wm, window_frame_node->frame, frame_attributes, 5);
            break;
        case 114:
            move_window_x(wm, window_frame_node->frame, frame_attributes, 5);
            break;
        case 113:
            move_window_x(wm, window_frame_node->frame, frame_attributes, -5);
            break;
    }
}

void move_window_left(WindowManager *wm, Window window) {

}