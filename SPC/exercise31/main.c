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

#define MAX_ARR_SIZE 10
#define MATRIX_SIZE 2

int array[MAX_ARR_SIZE] = {0};
int array2d[MATRIX_SIZE][MAX_ARR_SIZE] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}}; // Declaring a 2D array with 2 rows, 10 columns

static int *randomNumbers(void);
void printNumbers(int *array);
void printMatrix(int *array2d);

int main(void)
{

    printNumbers(randomNumbers());
    printMatrix(*array2d);
    (void)printf("\n");
    return 0;
}

static int *randomNumbers(void)
{
    srand(time(NULL));
    // This is where the random numbers are getting generated and stored in the array
    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        *(array + i) = rand() % 100;
        // This is where I check the number just generated so it doesn't match any other in the array, creating a new one if it finds it already in the array
        for (int j = 0; j < MAX_ARR_SIZE; j++)
        {
            if (*(array + j) == *(array + i))
            {
                *(array + i) = rand() % 100;
            }
        }
    }

    return array;
}

void printNumbers(int *array)
{
    printf("These are the array numbers: \n");
    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        (void)printf("%d\t", *(array + i));
    }
}

void printMatrix(int *array2d)
{
    printf("\nThese are the 2D array numbers: \n");
    for (int i = 0; i < MATRIX_SIZE * MAX_ARR_SIZE; i++)
    {
        (void)printf("%d\t", *(array2d + i));
    }
}