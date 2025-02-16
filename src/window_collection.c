#include <X11/X.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "window_collection.h"

WindowCollectionNode *create_window_collection_node(Window window, Window frame, WindowCollectionNode *next) {
    WindowCollectionNode *node = malloc(sizeof(WindowCollectionNode));

    if (node == NULL) {
        return NULL;
    }

    node->window = window;
    node->frame = frame;
    node->next = next;

    return node;
}


void window_collection_add(WindowCollection *collection, Window window, Window frame) {
    WindowCollectionNode* node;

    if (collection->nodes == NULL) {
        node = create_window_collection_node(window, frame, NULL);
    } else {
        node = create_window_collection_node(window, frame, collection->nodes);
    }

    if (node == NULL) {
        puts("Failed to allocate memory to the window node");
        exit(1);
    }

    collection->nodes = node;
}

WindowCollection *create_window_collection() {
    WindowCollection *collection = malloc(sizeof(WindowCollection));

    if (collection == NULL) {
        return NULL;
    }
  
    collection->nodes = NULL;  
    collection->length = 0;

    return collection;
}

void free_window_collection_nodes(WindowCollectionNode *root) {
    if (root->next != NULL) {
        return free_window_collection_nodes(root->next);
    }

   free(root); 
}

void free_window_collection(WindowCollection *collection) {
    free_window_collection_nodes(collection->nodes);
    free(collection); 
}
