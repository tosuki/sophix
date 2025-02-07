#ifndef ARRAY_H
#define ARRAY_H

#define DEFAULT_WINDOW_COLLECTION_CAPACITY 15
#define REALLOCATE_WINDOW_COLLECTION_FACTOR 2

#include <X11/Xlib.h>

typedef struct _windowCollection {
    Window* values;
    int capacity;
    int length;
} WindowCollection;

WindowCollection* createWindowCollection();

int getIndexOfWindowCollection(WindowCollection* windowCollection, Window window);
Window getWindowOfWindowCollectionByIndex(WindowCollection* windowCollection, int index);
void addWindowToWindowCollection(WindowCollection* windowCollection, Window window);
void freeWindowCollection(WindowCollection* windowCollection);

#endif
