/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int countDigits(int num);
int powerOf(int x, int y);

int main(void)
{
    // Declare a variable to check for number of digits, and a variable for storing the number of digits retrieved from the function
    int num = 456;
    int numOfDigits = 0;

    // Call the function and print the results
    numOfDigits = countDigits(num);
    (void)printf("The number %d has %d number of digits.\n", num, numOfDigits);

    // Declare variables to send to the power of function and one to store the result,
    int a = 2;
    int b = 3;
    int result = 0;
    // Call the function and print the results
    result = powerOf(a, b);
    (void)printf("%d\n", result);
    return 0;
}

int countDigits(int num)
{
    // To check if the number given is 0
    if (num == 0)
    {
        return 0;
    }
    // Recursion part, where the number is divided by 10 each time and return 1;
    return 1 + countDigits(num / 10);
}

int powerOf(int x, int y)
{
    // Storing the result of the multiplication in this variable
    int result = x;
    // To check the numbers given, if they're 0 nothing happens
    if (x == 0 || y == 0)
    {
        return 0;
    }
    // Doing the recursion, calling itself while multiplying x and y
    return 1 + powerOf(x *= y, y);
}