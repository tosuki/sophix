#include <stdio.h>
#include "./window_collection.h"
#include <X11/Xlib.h>

Window get_window(WindowNode* node) {
    if (node == NULL) {
        return -1;
    }

    return node->window;
}

int main() {
    //0 -> 1 -> 2
    WindowNode* node = createWindowNode(
        0, createWindowNode(
            1, createWindowNode(
                2,
                NULL
            )
        )
    );

    freeNextWindowNode(node);
    //0 -> 2 -> -1
    printf("%li -> %li -> %li\n", get_window(node), get_window(node->next), get_window(node->next->next));
}