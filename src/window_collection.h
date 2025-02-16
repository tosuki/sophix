#ifndef WINDOW_COLLECTION_H
#define WINDOW_COLLECTION_H

#include <X11/Xlib.h>

typedef struct WindowCollectionNode {
    Window window;
    Window frame;
    struct WindowCollectionNode* next;
} WindowCollectionNode;

typedef struct WindowCollection {
    WindowCollectionNode* nodes;
    unsigned int length;
} WindowCollection;

WindowCollectionNode* window_collection_get(WindowCollection *collection, Window window);
void window_collection_delete(WindowCollection *collection, Window window);
WindowCollectionNode* window_collection_add(WindowCollection *collection, Window window, Window frame);
WindowCollectionNode* create_window_collection_node(Window window, Window windowFrame, WindowCollectionNode *next);
void free_window_collection(WindowCollection* collection);
WindowCollection* create_window_collection();

#endif
