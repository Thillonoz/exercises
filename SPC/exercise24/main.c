#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define STR_MAX_LEN 20
#define YEAR 4
#define MON_DAY_HOUR_MIN_SEC 2
#define ERROR "Invalid input, try again."
#define YEAR_MIN 1000U
#define YEAR_MAX 9999U
#define MONTH 12U
#define HOUR 23U
#define MINUTE 59U
#define SECOND 59U

int main()
{
    char input[STR_MAX_LEN + 1] = {0};
    char *arraypointer = input;
    int temp[5] = {0};
    unsigned int year, month, day = 0;
    float temp3 = 0.0;
    bool leapYear = false;
    bool centuryLeap = false;
    printf("Enter a date in the format YYYY-MM-DD HH:mm:ss\n");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    for (int i = 0; i < YEAR; i++) // Checking the year
    {
        if (!isdigit(*(arraypointer + i)))
        {

            printf(ERROR);
            return 0;
        }
        temp[i] = *(arraypointer + i) - '0'; // Checking for leap year
    }

    year += temp[0] * 1000;
    year += temp[1] * 100;
    year += temp[2] * 10;
    year += temp[3] * 1;
    if (year < YEAR_MIN || year > YEAR_MAX)
    {
        printf(ERROR);
        return 0;
    }

    if (*(arraypointer + 2) == '0' && *(arraypointer + 3) == '0') // Checking for century leap year
    {

        if (year % 400 == 0)
        {
            printf("It's a century leap year.\n");
            centuryLeap = true;
        }
        else
        {
            centuryLeap = false;
        }
    }

    if (year % 4 == 0) // Checking for leap year
    {

        printf("It's a leap year.\n");
        leapYear = true;
    }
    else
    {
        printf("It's not a leap year.\n");
        leapYear = false;
    }

    if (*(arraypointer + 4) != '-') // Checking the -
    {
        printf(ERROR);
        return 0;
    }
    for (int i = 0; i < MON_DAY_HOUR_MIN_SEC; i++) // Checking the month
    {

        if (!isdigit(*(arraypointer + i)))
        {
            printf(ERROR);
            return 0;
        }
    }
    month += temp[5] * 10;
    month += temp[6] * 1;
    if (month > MONTH)
    {
        printf(ERROR);
        return 0;
    }
    if (*(arraypointer + 7) != '-') // Checking the -
    {
        printf(ERROR);
        return 0;
    }
    uint8_t days[MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < MON_DAY_HOUR_MIN_SEC; i++) // Checking the day
    {

        if (!isdigit(*(arraypointer + i)))
        {
            printf(ERROR);
            return 0;
        }
    }

    day += temp[8] * 10;
    day += temp[9] * 1;
    if (day > days[month - 1])
    {
        printf("Number of days are wrong");
        return 0;
    }
    if (leapYear == false) // Checking for invalid leap day
    {
        if (*(arraypointer + 8) == '2' && *(arraypointer + 9) == '9')
        {
            printf("Year given is not a leap year, so there cannot be a leap day, incorrect input.");
            return 0;
        }
    }
    if (!isspace(*(arraypointer + 10))) // Checking the space
    {
        printf(ERROR);
        return 0;
    }
    for (int i = 0; i < MON_DAY_HOUR_MIN_SEC; i++) // Checking the hour
    {

        if (!isdigit(*(arraypointer + i)))
        {
            printf(ERROR);
            return 0;
        }
    }

    if (*(arraypointer + 13) != ':') // Checking the :
    {
        printf(ERROR);
        return 0;
    }
    for (int i = 0; i < MON_DAY_HOUR_MIN_SEC; i++) // Checking the minute
    {

        if (!isdigit(*(arraypointer + i)))
        {
            printf(ERROR);
            return 0;
        }
    }
    if (*(arraypointer + 16) != ':') // Checking the :
    {
        printf(ERROR);
        return 0;
    }
    for (int i = 0; i < MON_DAY_HOUR_MIN_SEC; i++) // Checking the seconds
    {

        if (!isdigit(*(arraypointer + i)))
        {
            printf(ERROR);
            return 0;
        }
    }
    printf("Valid format.\n");
    return 0;
}