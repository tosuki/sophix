#include <stdio.h>
#include "./window_collection.h"
#include <X11/Xlib.h>

Window get_window(WindowNode* node) {
    if (node == NULL) {
        return -1;
    }

    return node->window;
}

void mapWindowNodes(WindowNode* start) {
    if (start == NULL) {
        return;
    }

    printf("%d\n", start->window);

    return mapWindowNodes(start->next);
}

int main() {
    WindowCollection* collection = createWindowCollection();

    windowCollectionAddItem(collection, 1);
    windowCollectionAddItem(collection, 2);
    windowCollectionAddItem(collection, 3);

    windowCollectionRemoveItem(collection, 2);

    mapWindowNodes(collection->nodes);

    return 0;
}