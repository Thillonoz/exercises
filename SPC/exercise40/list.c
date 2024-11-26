#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

struct list
{
    int counter;
    node_t *head;
};

list_t *list_create(void)
{

    list_t *ptr = (list_t *)malloc(sizeof(list_t));

    if (ptr != NULL)
    {
        ptr->counter = 0;
        ptr->head = NULL;
    }
    return ptr;
}

bool list_insert(list_t *lst, int value)
{
    bool status = false;
    if (lst != NULL)
    {
        node_t *ptr = (node_t *)malloc(sizeof(node_t));
        if (ptr != NULL)
        {
            status = true;
            lst->counter++;
            ptr->data = value;
            ptr->next = NULL;

            if (head == NULL)
            {
                head = ptr;
            }
            else
            {
                node_t *cursor = head;
                while (cursor->next != NULL)
                {
                    cursor = cursor->next;
                }

                cursor->next = ptr;
            }
        }
    }

    return (ptr != NULL);
}

void list_print(list_t *lst)
{
    if (lst == NULL)
    {
        printf("The list is empty\n");
    }
    else if (lst->head != NULL)
    {
        node_t *cursor = lst->head;
        while (cursor != NULL)
        {
            printf("%d\t", cursor->data);
            cursor = cursor->next;
        }
    }
    printf("\n");
}

bool list_remove(list_t *lst, int value)
{
    bool status = false;

    node_t *current = lst->head;
    node_t *previous = NULL;
    while (current != NULL)
    {
        if (current->data == value)
        {
            status = true;
            lst->counter--;
            if (previous == NULL)
            {
                lst->head = lst->head->next;
            }
            else
            {
                previous->next = current->next;
            }

            free(current);

            break;
        }
        previous = current;
        current = current->next;
    }
    return status;
}

int list_available(list_t *lst)
{
    return lst->counter;
}

void list_destroy(list_t *lst)
{
    node_t *cursor;

    while (lst->head != NULL)
    {
        cursor = lst->head;
        lst->head = lst->head->next;
        free(cursor);
    }
    lst->counter = 0;
}

// bool list_new_node(int data)
// {
//     bool status = true;

//     node_t *new_node = (node_t *)malloc(sizeof(node_t)); // Create a node

//     if (head == NULL) // The list is empty
//     {
//         head = new_node;
//     }

//     node_t *current = head;

//     while (current->next != NULL)
//     {
//         current = current->next;
//     }

//     /* now we can add a new variable */
//     current = (node_t *)malloc(sizeof(node_t));
//     if (current == NULL)
//     {
//         status = false;
//     }

//     current->data = val;
//     printf("%d\n", current->data);
//     current->next = NULL;

//     return status;
// }

// bool list_change_data(size_t n, int value)
// {
//     size_t position = 1;
//     node_t *cursor = (n > 0) ? head : NULL;

//     while ((position < n) && (cursor != NULL))
//     {
//         cursor = cursor->next;
//         position++;
//     }

//     if (cursor != NULL)
//     {
//         cursor->data = value;
//     }

//     return (cursor != NULL);
// }