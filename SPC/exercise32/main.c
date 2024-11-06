/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 10

void randomNumbers(int *arr);
void printNumbers(int *array);
void swap(int *x, int *y);
typedef bool (*compare_t)(int, int);
void sort_array(int *arr, compare_t compare);
bool compare_asc(int a, int b);
bool compare_desc(int a, int b);

int main(void)
{
    // Initializing the array, filling the array with random numbers and printing them
    int arr[MAX_ARRAY_SIZE] = {0};
    randomNumbers(arr);
    printf("Original array: \n");
    printNumbers(arr);

    // Sorting the array in an ascending order and printing them
    sort_array(arr, compare_asc);
    (void)printf("Sorted array (ascending):\n");
    printNumbers(arr);

    // Sorting the array in descending order and printing them
    sort_array(arr, compare_desc);
    (void)printf("Sorted array (descending):\n");
    printNumbers(arr);

    return 0;
}

void randomNumbers(int *arr)
{
    srand(time(NULL));
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        *(arr + i) = rand() % 100;
    }
}

void printNumbers(int *arr)
{
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        (void)printf("%d\t", *(arr + i));
    }
    (void)printf("\n");
}

void swap(int *x, int *y)
{
    uint8_t temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sort_array(int *arr, compare_t compare)
{
    for (size_t i = 0; i < MAX_ARRAY_SIZE - 1; i++)
    {
        for (size_t j = 0; j < MAX_ARRAY_SIZE - i - 1; j++)
        {
            if (compare(*(arr + j), *(arr + j + 1)))
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

bool compare_asc(int a, int b)
{
    return a > b;
}

bool compare_desc(int a, int b)
{
    return a < b;
}