#ifndef JEP_COLLECTION_H
#define JEP_COLLECTION_H

/**
 * Collection
 *
 * A linked list utility library.
 */

typedef struct jep_node
{
    void* data;
    struct jep_node* next;
    struct jep_node* prev;
    struct jep_node* last;
} jep_node;

/**
 * A type definition for a function to free the memory
 * allocated for the data inside a node.
 */
typedef void(*data_destructor)(void*);

/**
 * Creates a new node.
 * A new node may be used as the root node of a new collection.
 *
 * Params:
 *   void* - a pointer to some data
 *
 * Returns:
 *   jep_node* - a pointer to a new node
 */
jep_node* jep_create_node(void* data);

/**
 * Frees the resources allocated for a node.
 *
 * Params:
 *   jep_node* - a pointer to the node to destroy
 *   data_destructor - a function to destroy the data within a node
 */
void jep_destroy_node(jep_node* n, data_destructor des);

/**
 * Frees the resources allocated for a collection.
 *
 * Params:
 *   jep_node* - a pointer to the root node of a collection
 *   data_destructor - a function to destroy the data within a node
 */
void jep_destroy_collection(jep_node* col, data_destructor des);

/**
 * Appends a node onto the end of a collection.
 *
 * Params:
 *   jep_node* - a pointer to the root node of a collection
 *   jep_node* - a pointer to the new node to add to the collection
 */
void jep_push_node(jep_node* col, jep_node* next);

/**
 * Removed a node from the end of a collection.
 * This does not free any memory. It only updates the internal
 * pointers of the collection so that the last node is no longer
 * part of the linked list.
 *
 * Params:
 *   jep_node* - a pointer to the root node of a collection
 *
 * Returns:
 *   jep_node* - a pointer to the node that was removed from the collection
 */
jep_node* jep_pop_node(jep_node* col);

#endif