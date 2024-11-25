#include "linkedlist.h"
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node_t;

static node_t *head = NULL;

bool newNode(int val)
{
    bool status = true;

    node_t *new_node = (node_t *)malloc(sizeof(node_t)); // Create a node

    if (head == NULL) // The list is empty
    {
        head = new_node;
    }

    node_t *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    /* now we can add a new variable */
    current = (node_t *)malloc(sizeof(node_t));
    if (current == NULL)
    {
        status = false;
    }

    current->data = val;
    printf("%d\n", current->data);
    current->next = NULL;

    return status;
}

bool changeValue(size_t n, int value)
{
    size_t position = 1;
    node_t *cursor = (n > 0) ? head : NULL;

    while ((position < n) && (cursor != NULL))
    {
        cursor = cursor->next;
        position++;
    }

    if (cursor != NULL)
    {
        cursor->data = value;
    }
    
    return (cursor != NULL);
}