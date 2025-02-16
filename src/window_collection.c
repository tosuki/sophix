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

WindowCollectionNode* window_collection_node_get(WindowCollectionNode *root, Window window) {
    if (root == NULL) {
        return NULL;
    }

    if (root->window == window) {
        return root;
    }

    return window_collection_node_get(root->next, window);
}

WindowCollectionNode* window_collection_get(WindowCollection *collection, Window window) {
    return window_collection_node_get(collection->nodes, window);
}

WindowCollectionNode *window_collection_get_previous(WindowCollectionNode* root, Window window) {
    if (root->window == window || root->next == NULL) {
        return NULL;
    }

    if (root->next->window == window) {
        return root;
    }

    return window_collection_get_previous(root->next, window);
}

void window_collection_node_free_next(WindowCollectionNode *node) {
    if (node->next == NULL) {
        return;
    }

    if (node->next->next != NULL) {
        WindowCollectionNode *next;
        free(node->next);
        node->next = next;

        return;
    }

    free(node->next);
}

void window_collection_delete(WindowCollection *collection, Window window) {
    if (collection->nodes == NULL) {
        puts("Attempt to delete a window that is not cached");
        return;
    }

    if (collection->nodes->window == window) {
        WindowCollectionNode* next = collection->nodes->next;
        free(collection->nodes);
        collection->nodes = next;

        if (collection->length > 1) {
            collection->length -= 1;
        }
    } else {
        WindowCollectionNode *previous_node = window_collection_get_previous(collection->nodes, window);
        
        if (previous_node == NULL) {
            return;
        }

        window_collection_node_free_next(previous_node);
    }
}

WindowCollectionNode *window_collection_add(WindowCollection *collection, Window window, Window frame) {
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
    collection->length += 1;

    return node;
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
