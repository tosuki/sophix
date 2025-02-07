#include <stdio.h>
#include <malloc.h>
#include <X11/Xlib.h>

#include "./window_collection.h"
#include "./lib/utils.h"

void* allocateWindowCollectionMemory(WindowCollection* windowCollection) {
    windowCollection->values = malloc(sizeof(Window)*windowCollection->capacity);

    if (windowCollection->values == NULL) {
        panic("Failed to allocate memory to window collection values!");
    }

    return windowCollection->values;
}

WindowCollection* createWindowCollection() {
    WindowCollection* windowCollection = malloc(sizeof(WindowCollection));

    if (windowCollection == NULL) {
        panic("Failed to allocate memory to window collection");
    }

    windowCollection->capacity  = DEFAULT_WINDOW_COLLECTION_CAPACITY;
    windowCollection->length = 0;
    windowCollection->values = allocateWindowCollectionMemory(windowCollection);

    return windowCollection;
}

void reallocateWindowCollectionMemory(WindowCollection* windowCollection) {
    windowCollection->capacity = windowCollection->capacity * REALLOCATE_WINDOW_COLLECTION_FACTOR;
    allocateWindowCollectionMemory(windowCollection);
}

void addWindowToWindowCollection(WindowCollection* windowCollection, Window window) {
    if (windowCollection->length >= windowCollection->capacity) {
        //window collection is full
        reallocateWindowCollectionMemory(windowCollection);
    }

    windowCollection->values[windowCollection->length] = window;
    windowCollection->length += 1;
    printf("Added window %li to the collection: [L:%d, C:%d]\n", window, windowCollection->length, windowCollection->capacity);
}

int getIndexOfWindowCollection(WindowCollection* windowCollection, Window window) {
    int windowIndex = -1;

    for (int i = 0; i < windowCollection->length; i++) {
        if (windowCollection->values[i] == window) {
            windowIndex = i;
        }
    }

    return windowIndex;
}

Window getWindowOfWindowCollectionByIndex(WindowCollection* windowCollection, int index) {
    return windowCollection->values[index];
}

void freeWindowCollection(WindowCollection* windowCollection) {
    free(windowCollection);
}
