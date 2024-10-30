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
#include <stdint.h>

#define ARRAY_SIZE 10

uint8_t arr[ARRAY_SIZE] = {1, 23, 3, 4, 10, 6, 7, 11, 9, 55};

void largestNumber(uint8_t arr[ARRAY_SIZE]);
void average(uint8_t arr[ARRAY_SIZE]);
int8_t find(uint8_t arr[ARRAY_SIZE]);

int main()
{
    int8_t foundNumber = 0;
    largestNumber(arr);
    average(arr);
    foundNumber = find(arr);
    if (foundNumber == -1)
    {
        printf("Number not in the array\n");
    }
    else
    {
        printf("Number found %d\n", foundNumber);
    }

    return 0;
}

void largestNumber(uint8_t arr[ARRAY_SIZE])
{
    uint8_t temp = 0;

    for (uint8_t i = 0; i < ARRAY_SIZE - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    (void)printf("%d\n", arr[ARRAY_SIZE - 1]);
}

void average(uint8_t arr[ARRAY_SIZE])
{
    uint8_t sum = 0;

    for (uint8_t i = 0; i < ARRAY_SIZE - 1; i++)
    {
        sum += arr[i];
    }
    float average = (float)sum / ARRAY_SIZE;
    printf("%.1f\n", average);
}

int8_t find(uint8_t arr[ARRAY_SIZE])
{
    uint8_t num = 0;
    uint8_t look = 6;

    for (uint8_t i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i] == look)
        {
            num = arr[i];
            return num;
        }
    }

    return -1;
}