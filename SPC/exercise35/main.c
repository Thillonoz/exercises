/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
    int input = atoi(argv[1]);

    (void)printf("The number %d %s prime\n", input, primeCheck(input) ? "is a" : "is not a");

    return 0;
}