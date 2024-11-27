#include <stdio.h>

typedef struct list
{
    int data;
    struct list *next;
    struct list *previous;
} list_t;

int main(void)
{

    list_t lst;

    lst.data = 10;
    lst.next = NULL;
    lst.previous = NULL;

    list_t lst1;

    lst1.data = 20;
    lst1.next = NULL;
    lst1.previous = &lst;

    list_t lst2;

    lst2.data = 30;
    lst2.next = NULL;
    lst2.previous = &lst1;

    list_t lst3;

    lst3.data = 40;
    lst3.next = NULL;
    lst3.previous = &lst2;

    list_t lst4;

    lst4.data = 50;
    lst4.next = NULL;
    lst4.previous = &lst3;

    list_t lst5;

    lst5.data = 60;
    lst5.next = NULL;
    lst5.previous = &lst4;

    list_t lst6;

    lst6.data = 70;
    lst6.next = NULL;
    lst6.previous = &lst5;

    lst.next = &lst1;
    lst1.next = &lst2;
    lst2.next = &lst3;
    lst3.next = &lst4;
    lst4.next = &lst5;
    lst5.next = &lst6;

    list_t *head = &lst;
    list_t *tail = &lst6;

    for (list_t *current = head; current != NULL; current = current->next)
    {

        (void)printf("%d -> ", current->data);
    }
    (void)printf("NULL \n");

    for (list_t *current = tail; current != NULL; current = current->previous)
    {

        (void)printf("%d -> ", current->data);
    }
    (void)printf("NULL \n");

    list_t lstInserted;

    lstInserted.data = 15;
    lstInserted.next = &lst1;
    lstInserted.previous = &lst;
    lst.next = &lstInserted;
    lst1.previous = &lstInserted;

    for (list_t *current = head; current != NULL; current = current->next)
    {

        (void)printf("%d -> ", current->data);
    }
    (void)printf("NULL \n");

    for (list_t *current = tail; current != NULL; current = current->previous)
    {

        (void)printf("%d -> ", current->data);
    }
    (void)printf("NULL \n");

    return 0;
}