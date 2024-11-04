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

#define MAX_ARRAY_SIZE 10
#define MIN_VALUE 0
#define MAX_VALUE 99

int array[MAX_ARRAY_SIZE] = {0};

static int *randomNumbers(void);
void printNumbers(int *array);
void swap(uint8_t x, uint8_t y);

int main(void)
{
    uint8_t var = 10;
    uint8_t var1 = 15;
    printNumbers(randomNumbers());
    (void)printf("\n");
    swap(var, var1);
    return 0;
}

static int *randomNumbers(void)
{
    srand(time(NULL));
    // This is where the random numbers are getting generated and stored in the array
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        *(array + i) = rand() % 100;
        // This is where I check the number just generated so it doesn't match any other in the array, creating a new one if it finds it already in the array
        for (int j = 0; j < MAX_ARRAY_SIZE; j++)
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
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        (void)printf("%d\t", *(array + i));
    }
}

void swap(uint8_t x, uint8_t y)
{
    (void)printf("Before the swap, these are the values of var (x in this scope), and var1 (y in this scope).\n");
    (void)printf("Value of x: %u\nValue of y: %u\n", x, y);
    uint8_t temp = 0;
    temp = x;
    x = y;
    y = temp;
    (void)printf("After the swap, this is now the values\n");
    (void)printf("Value of x: %u\nValue of y: %u\n", x, y);
}