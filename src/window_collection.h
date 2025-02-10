#ifndef WINDOW_COLLECTION_H
#define WINDOW_COLLECTION_H

#include <X11/Xlib.h>

typedef struct _WindowNode {
    Window windowFrame;
    Window window;
    struct _WindowNode* next;
} WindowNode;

typedef struct WindowCollection {
    WindowNode* nodes;
    int size;
} WindowCollection;

WindowCollection* createWindowCollection();
void windowCollectionAddItem(WindowCollection* windowCollection, Window window, Window windowFrame);
WindowNode* windowCollectionGetItem(WindowCollection* windowCollection, Window windowId);
WindowCollection* windowCollectionRemoveItem(WindowCollection* windowCollection, Window windowId);
WindowNode* createWindowNode(Window window, Window windowFrame, WindowNode* next);
WindowNode* freeNextWindowNode(WindowNode* node);
WindowNode* getPreviousWindowNode(WindowNode* start, Window windowId);

#endif
