#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
typedef struct list list_t;

list_t *list_create(void);

bool list_insert(list_t *lst, int value);

void list_print(list_t *lst);

bool list_remove(list_t *lst, int value);

int list_available(list_t *lst);

void list_destroy(list_t *lst);
// bool list_new_node(int data);
// bool list_change_data(size_t n, int value);

#endif