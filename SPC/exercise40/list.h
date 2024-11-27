#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef struct list list_t;

/**
 * @brief This function is used to create a new list
 *
 * @param lst Passing the list to the function
 * @return list_t*
 */
list_t *list_create(list_t *lst);

/**
 * @brief This function is for inserting new nodes in the given list
 *
 * @param lst Passing the list to the function
 * @param value
 * @return true
 * @return false
 */
bool list_insert(list_t *lst, int value);

bool list_new_insert(list_t *lst, int value);

/**
 * @brief Function to print a given list
 *
 * @param lst Passing the list to the function
 */
void list_print(list_t *lst);

/**
 * @brief Function to remove data from a list
 *
 * @param lst Passing the list to the function
 * @param value
 * @return true
 * @return false
 */
bool list_remove(list_t *lst, int value);

/**
 * @brief Function to check available number of elements in a list
 *
 * @param lst Passing the list to the function
 * @return int
 */
int list_available(list_t *lst);

/**
 * @brief Function to change data in a list
 *
 * @param lst Passing the list to the function
 * @param n
 * @param value
 * @return true
 * @return false
 */
bool list_change_data(list_t *lst, size_t n, int value);

/**
 * @brief Function to get the nth element of a list
 *
 * @param lst Passing the list to the function
 * @param n The nth position of the list which is retrieved
 * @return size_t
 */
size_t list_get_data(list_t *lst, int n);

/**
 * @brief Function to search for an element in the list
 *
 * @param lst Passing the list to the function
 * @param value
 * @return true
 * @return false
 */
bool list_search(list_t *lst, int value);

/**
 * @brief Function to destroy a list
 *
 * @param lst Passing the list to the function
 */
void list_destroy(list_t *lst);

#endif