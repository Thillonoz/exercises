/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdint.h>

int primeCheck(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    uint8_t m = 23;
    uint8_t n = 243;
    uint8_t printing = 0;
    for (int i = m; i < n; i++)
    {
        printing = i;
        if (primeCheck(i))
        {
            printf("%hhu\t", printing);
        }
    }
    return 0;
}