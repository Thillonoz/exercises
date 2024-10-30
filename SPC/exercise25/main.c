/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_SIZE 10

static uint8_t *randomNumbers(void);
void printNumbers(uint8_t *);

int main()
{

    printNumbers(randomNumbers());

    (void)printf("\n");
    return 0;
}

static uint8_t *randomNumbers(void)
{
    static uint8_t arr[ARRAY_SIZE] = {0};
    srand(time(NULL));
    // printf("These are the random numbers: \n");
    for (uint8_t i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        //(void)printf("%d\t", arr[i]);
        for (uint8_t j = 0; j < ARRAY_SIZE; j++)
        {
            if (arr[j] == arr[i])
            {
                arr[i] = rand() % 100;
            }
        }
    }
    (void)printf("\n");
    return arr;
}

void printNumbers(uint8_t *arr)
{

    printf("These are the array numbers: \n");
    for (uint8_t i = 0; i < ARRAY_SIZE; i++)
    {
        (void)printf("%d\t", arr[i]);
    }
}