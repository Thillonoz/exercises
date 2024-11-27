#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList list_t;

/**
 * @brief This function is used to create a new list
 *
 * @param lst
 * @return list_t*
 */
list_t *list_create(list_t *lst);

/**
 * @brief This function is for inserting new nodes in the given list
 *
 * @param lst
 * @param value
 * @return true
 * @return false
 */
bool list_insert(list_t *lst, int value);

/**
 * @brief Function to print a given list
 *
 * @param lst
 */
void list_print(list_t *lst);

/**
 * @brief Function to remove data from a list
 *
 * @param lst
 * @param value
 * @return true
 * @return false
 */
bool list_remove(list_t *lst, int value);

/**
 * @brief Function to check available number of elements in a list
 *
 * @param lst
 * @return int
 */
int list_available(list_t *lst);

/**
 * @brief Function to change data in a list
 *
 * @param lst
 * @param n
 * @param value
 * @return true
 * @return false
 */
bool list_change_data(list_t *lst, size_t n, int value);

bool list_search(list_t *lst, int value);

/**
 * @brief Function to destroy a list
 *
 * @param lst
 */
void list_destroy(list_t *lst);

#endif