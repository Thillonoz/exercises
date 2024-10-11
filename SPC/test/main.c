/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>

struct
{

    unsigned bit : 2;
} date;

int main()
{

    // date.day = 7, date.month = 8, date.year = 1992;
    date.bit = 3;

    // printf("%d-%02d-%02d\n", date.year, date.month, date.day);
    int a = 102;
    printf("\%c %d\n", a);

    return 0;
}