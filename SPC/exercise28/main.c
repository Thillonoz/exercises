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

#define MAX_LEN 15

uint8_t stringCompare(void);

int main()
{
    (void)printf("%s\n", stringCompare() ? "Matching" : "Not matching");
    return 0;
}

uint8_t stringCompare(void)
{
    char string1[MAX_LEN] = "Hello World";
    char string2[MAX_LEN] = "Hello World";
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (string1[i] != string2[i])
        {
            return 0;
            break;
        }
    }
    return 1;
}