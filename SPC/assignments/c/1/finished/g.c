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
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define FORMAT "YYMMDD-nnnn" // Expected format
#define ERROR "Invalid input, try again. Correct format: %s\n"
#define PERS_NUM_LEN 10 // The number of digits in a swedish personal number
#define INPUT_LEN 11    // Number of digits + '-'
#define MONTH_MIN 1
#define MONTH_MAX 12
#define DAY_MIN 1
#define DAY_MAX 31

bool isLeapYear(uint8_t year);
bool isValidDate(uint8_t year, uint8_t month, uint8_t day);
bool checkPersonalNumber(const uint8_t *personNumber);

int main(void)
{
    char input[INPUT_LEN] = {0};
    uint8_t year = 0, month = 0, day = 0, serial = 0;
    uint8_t parsedInput[INPUT_LEN] = {0};
    bool result = false;

    (void)printf("Please enter your personal number (%s) to check if it's valid: \n", FORMAT);

    // Limits the input and checks if scanf succeeds in reading the input
    if (scanf("%11s", input) != 1)
    {
        (void)printf(ERROR, FORMAT);
        exit(1);
    }

    // Checking that input is only numbers (except for the hyphen)
    for (size_t i = 0; i < INPUT_LEN; i++)
    {
        if (i == 6) // Skip '-'
        {
            continue;
        }

        if (!isdigit(input[i]))
        {
            (void)printf(ERROR, FORMAT);
            exit(1);
        }
    }

    // Use sscanf to parse the input
    if (sscanf(input, "%2hhu%2hhu%2hhu-%4hhu", &year, &month, &day, &serial) == 4)
    {
        // Convert 2-digit year to 4-digit by adding 1900 or 2000 (assuming 00-99 as 1900-1999 or 2000-2099)
        uint8_t full_year = (year <= 99) ? (year >= 24 ? 1900 + year : 2000 + year) : year;

        // Validate the date and display an error if invalid
        if (!isValidDate(full_year, month, day))
        {
            (void)printf(ERROR, FORMAT);
            exit(1);
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

// Checks if a year is a leap year
bool isLeapYear(uint8_t year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Validates if the given day is correct for the month and year
bool isValidDate(uint8_t year, uint8_t month, uint8_t day)
{
    if (month < 1 || month > 12 || day < 1)
        return false;

    uint8_t days_in_month[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return day <= days_in_month[month - 1];
}

// Validates Swedish personal number check digit
bool checkPersonalNumber(const uint8_t *personNumber)
{
    uint8_t checkDigit = 0, product = 0;
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
