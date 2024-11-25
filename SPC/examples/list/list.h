/**
 * @file list.h
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief A single instance linked list module to store data of type int.
 *        The module shall provide:
 *          1) A function to insert a new data element into the linked list
 *          2) A function to get number of the data elements stored in the linked list
 *          3) A function to delete the nth node in the list
 *          4) A function to search for a specific value
 *          5) A function to get data stored in the nth node.
 *          6) A function to to update the nth node of the list.
 *          7) A function to delete all the nodes in the linked list
 *
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief This function is used to insert a data element into the list.
 *
 * @param data The integer to insert.
 * @return bool - true if value is inserted successfully; otherwise false
 */
bool list_insert(int value);

/**
 * @brief This function returns number of the data elements stored in the list.
 *
 * @return size_t - Number of the data elements
 */
size_t list_available(void);

/**
 * @brief This function is used to search for a specific data in the list.
 *
 * @param value The data to search for.
 * @return size_t - 0 if data is not in the list; otherwise position of the data in the list started from 1.
 */
size_t list_find(int value);

/**
 * @brief This function is used to get the data stored int the nth element of the list.
 *
 * @param n The nth node. n shall be a valid position and greater than 0
 * @param ptr An int pointer which holds address of a variable to store the data in.
 * @return bool - false if n or ptr is not valid; otherwise true
 */
bool list_get_data(size_t n, int *iptr);

/**
 * @brief This function is used to delete the nth node in the list
 *
 * @param n The nth node
 * @return bool - false if n is invalid; otherwise true
 */
bool list_remove(size_t n);

/**
 * @brief This function is used to update the nth node of the list.
 *
 * @param n The nth element. n shall be a valid position and greater than 0
 * @param value The new value to store
 * @return bool - false if n is invalid; otherwise true
 */
bool list_update(size_t n, int value);

/**
 * @brief This function is used to free the allocated memory for all the nodes.
 *
 */
void list_delete(void);

#endif