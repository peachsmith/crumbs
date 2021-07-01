#include <stdlib.h>

#include "collection.h"

jep_node* jep_create_node(void* data)
{
    jep_node* n = (jep_node*)malloc(sizeof(jep_node));

    if (n == NULL)
    {
        return NULL;
    }

    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    n->last = n;

    return n;
}

void jep_destroy_node(jep_node* n, data_destructor des)
{
    des(n->data);
    free(n);
}

void jep_destroy_collection(jep_node* col, data_destructor des)
{
    while (col)
    {
        jep_node* next = col->next;
        jep_destroy_node(col, des);
        col = next;
    }
}

void jep_push_node(jep_node* col, jep_node* next)
{
    if (col == NULL || next == NULL)
    {
        return;
    }

    // Set the last node's next pointer to be the new node.
    col->last->next = next;

    // Set the new node's prev pointer to be the last node.
    next->prev = col->last;

    // The last node in the collection is now the new node.
    col->last = next;
}

jep_node* jep_pop_node(jep_node* col)
{
    jep_node* last = col->last;

    if (last != NULL && last->prev != NULL)
    {
        col->last = last->prev;
        col->last->next = NULL;
    }

    return last;
}
