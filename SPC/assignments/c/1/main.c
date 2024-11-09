/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief A program to check and validate a user input swedish personal number
 * @version 0.1
 * @date 2024-11-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define FORMAT "YYMMDD-NNNN" // Expected format
#define ERROR "Invalid input, try again (%s)\n"
#define PERS_NUM_LEN 10 // The number of digits in a swedish personal number
#define INPUT_LEN 11    // Number of digits + '-'
#define MONTH_MIN 1
#define MONTH_MAX 12
#define DAY_MIN 1
#define DAY_MAX 31

bool checkPersonalNumber(const int8_t *personNumber);

int main(void)
{
    char input[INPUT_LEN] = {0};
    int8_t year = 0, month = 0, day = 0, serial = 0;
    int8_t parsedInput[INPUT_LEN] = {0};
    bool result = false;

    (void)printf("Please enter your personal number (%s) to check if it's valid: \n", FORMAT);

    // Limits the input and checks if scanf succeeds in reading the input
    if (scanf("%11s", input) != 1)
    {
        (void)printf(ERROR, FORMAT);
        return 0;
    }

    // Use sscanf to parse the input
    if (sscanf(input, "%2hhd%2hhd%2hhd-%4hhd", &year, &month, &day, &serial) == 4)
    {
        // Check date range and display an error if invalid
        if (month < MONTH_MIN || month > MONTH_MAX || day < DAY_MIN || day > DAY_MAX)
        {
            (void)printf(ERROR, FORMAT);
            return 0;
        }

        // Convert input characters to integers
        for (size_t i = 0; i < INPUT_LEN; i++)
        {
            parsedInput[i] = input[i] - '0';
        }

        // Validate the personal number and display result
        result = checkPersonalNumber(parsedInput);
        (void)printf("The number %s valid!\n", result ? "is" : "is not");
    }
    else
    {
        (void)printf(ERROR, FORMAT);
    }
    return 0;
}
// Validates Swedish personal number check digit
bool checkPersonalNumber(const int8_t *personNumber)
{
    int8_t checkDigit = 0, product = 0;
    for (size_t i = 0, j = 0; i < PERS_NUM_LEN - 1; i++, j++)
    {
        if (i == 6) // Skip the '-'
        {
            j++;
        }

        // Arithmetic for the PIN, alternate multiply by 2 and 1
        product = (i % 2 == 0) ? personNumber[j] * 2 : personNumber[j];

        // Add digits for numbers >= 10
        checkDigit += (product >= 10) ? product / 10 + product % 10 : product;
    }

    checkDigit = (10 - (checkDigit % 10)) % 10;

    return (checkDigit == personNumber[PERS_NUM_LEN]);
}