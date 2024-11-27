#include "list.h"
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

static node_t *head = NULL;
static size_t available = 0;

bool list_insert(int value)
{
    bool status = false;

    node_t *new_node = (node_t *)malloc(sizeof(node_t)); // Create a node

    if (new_node != NULL)
    {
        available++;
        status = true;
        new_node->next = NULL;
        new_node->data = value;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            node_t *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    return status;
}

size_t list_available(void)
{
    return available;
}

size_t list_find(int value)
{
    size_t counter = 0;
    size_t position = 0;
    node_t *cursor = head;

    while (cursor != NULL)
    {
        counter++;

        if (cursor->data == value)
        {
            position = counter;
            break;
        }

        cursor = cursor->next;
    }

    return position;
}

bool list_get_data(size_t n, int *iptr)
{
    node_t *cursor = NULL;

    if (iptr != NULL)
    {
        size_t position = 1;
        cursor = (n > 0) ? head : NULL;

        while ((position < n) && (cursor != NULL))
        {
            cursor = cursor->next;
            position++;
        }

        if (cursor != NULL)
        {
            *iptr = cursor->data;
        }
    }

    return (cursor != NULL);
}

bool list_remove(size_t n)
{
    size_t position = 1;
    node_t *previous = NULL;
    node_t *current = (n > 0) ? head : NULL;

    while ((position < n) && (current != NULL))
    {
        previous = current;
        current = current->next;
        position++;
    }

    if (current != NULL)
    {
        if (previous == NULL)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        available--;
        free(current);
    }

    return (current != NULL);
}

bool list_update(size_t n, int value)
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

void list_delete(void)
{
    while (head != NULL)
    {
        node_t *next = head->next;
        free(head);
        head = next;
    }
    available = 0;
}