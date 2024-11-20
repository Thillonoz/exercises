/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief Program to have a given array of type uint8_t sorted, checked and tested
 * @version 0.1
 * @date 2024-11-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "functions.h"

int main(void)
{
    uint8_t array[10] = {10, 4, 8, 3, 7, 6, 8, 2, 9, 1};
    uint8_t length = sizeof(array) / sizeof(array[0]);

    (void)printf("The unsorted array:\n");
    for (uint8_t i = 0; i < length; i++)
    {
        (void)printf("%hhu\t", array[i]);
    }
    (void)printf("\n");

    testSort(array, length);

    return 0;
}