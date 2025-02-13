#include <malloc.h>
#include <X11/Xlib.h>

#include "./window_collection.h"
#include "./lib/utils.h"

WindowCollection* createWindowCollection() {
    WindowCollection* collection = malloc(sizeof(WindowCollection));

    if (collection == NULL) {
        panic("Failed to allocate memory to the window collection");
    }

    collection->nodes = NULL;
    collection->size = 0;

    return collection;
}

WindowNode* createWindowNode(Window window, Window windowFrame, WindowNode* next) {
    WindowNode* node = malloc(sizeof(WindowNode));

    if (node == NULL) {
        panic("Failed to allocate memory to the WindowNode");
    }

    node->window = window;
    node->windowFrame = windowFrame;
    node->next = next;

    return node;
}

WindowNode* freeNextWindowNode(WindowNode* node) {
    if (node->next == NULL) {
        return node;
    }

    if (node->next->next == NULL) {
        free(node->next);
        return node;
    }

    WindowNode* last = node->next->next;
    free(node->next);
    node->next = last;

    return node;
}

void windowCollectionAddItem(WindowCollection* windowCollection, Window window, Window windowFrame) {
    if (windowCollection->nodes == NULL) {
        windowCollection->nodes = createWindowNode(window, NULL);
    } else {
        windowCollection->nodes = createWindowNode(
            window,
            windowCollection->nodes
        );
    }
}

WindowNode* getWindowNode(WindowNode* root, Window value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->window == value) {
        return root;
    }

    if (root->next != NULL) {
        return getWindowNode(root->next, value);
    }

    return NULL;
}

WindowNode* windowCollectionGetItem(WindowCollection* windowCollection, Window windowId) {
    return getWindowNode(windowCollection->nodes, windowId);    
}

WindowNode* getPreviousWindowNode(WindowNode* start, Window windowId) {
    if (start == NULL || start->next == NULL) {
        return NULL;
    }

    if (start->next->window == windowId) {
        return start;
    }

    return getPreviousWindowNode(start->next, windowId);
}


WindowCollection* windowCollectionRemoveItem(WindowCollection* windowCollection, Window windowId) {

    if (windowCollection->nodes == NULL) {
        return windowCollection; 
    }

    if (windowCollection->nodes->window == windowId) {
        WindowNode* nextNode = windowCollection->nodes->next;

        free(windowCollection->nodes);
        windowCollection->nodes = nextNode;

        return windowCollection;
    } else {
        WindowNode* previous = getPreviousWindowNode(windowCollection->nodes, windowId);

        if (previous == NULL) {
            return windowCollection;
        }

        freeNextWindowNode(previous);

        return windowCollection;
    }

    return windowCollection;
}
