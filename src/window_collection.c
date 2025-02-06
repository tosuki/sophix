#include <stdio.h>
#include <malloc.h>
#include <X11/Xlib.h>

#include "./window_collection.h"
#include "./lib/utils.h"
/**
 * 
 * PLEASE GOD, TELL ME I WONT HAVE TO IMPLEMENT A HASHMAP AGAIN 
 */
void* allocateWindowCollectionMemory(WindowCollection* windowCollection) {
    windowCollection->values = malloc(sizeof(Window)*windowCollection->capacity);

    if (windowCollection->values == NULL) {
        panic("Failed to allocate memory to window collection values!");
    }

    return windowCollection->values;
}

WindowCollection* createWindowCollection(int initialCapacity) {
    WindowCollection* windowCollection = malloc(sizeof(windowCollection));

    if (windowCollection == NULL) {
        panic("Failed to allocate memory to window collection");
    }

    windowCollection->capacity  = initialCapacity || DEFAULT_WINDOW_COLLECTION_CAPACITY;
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
}

void freeWindowCollection(WindowCollection* windowCollection) {
    free(windowCollection);
}
