#include "list.h"

typedef struct node
{
    int data;
    struct node *next;
} node_t;

struct LinkedList
{
    int size;
    node_t *head;
};

list_t *list_create(list_t *lst)
{

    list_t *ptr = (list_t *)malloc(sizeof(list_t));

    if (ptr != NULL)
    {
        ptr->size = 0;
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
            lst->size++;
            ptr->data = value;
            ptr->next = NULL;

            if (lst->head == NULL)
            {
                lst->head = ptr;
            }
            else
            {
                node_t *cursor = lst->head;
                while (cursor->next != NULL)
                {
                    cursor = cursor->next;
                }

                cursor->next = ptr;
            }
        }
    }

    return (lst != NULL);
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
            lst->size--;
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
        if (current->next != NULL)
        {
            current = current->next;
        }

       // current = current->next;
    }
    return status;
}

int list_available(list_t *lst)
{
    return lst->size;
}

bool list_change_data(list_t *lst, size_t n, int value)
{
    size_t position = 1;
    node_t *cursor = (n > 0) ? lst->head : NULL;

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

bool list_search(list_t *lst, int value)
{
    size_t position = 1;
    bool status = false;
    node_t *cursor = (value >= 0) ? lst->head : NULL;

    do
    {
        if (cursor->data == value)
        {
            status = true;
            break;
        }

        cursor = cursor->next;
        position++;
    } while ((cursor->data != value) && (cursor != NULL));

    return status;
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
    lst->size = 0;
}