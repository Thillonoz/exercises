#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_MAX_LEN 30
#define YEAR 4
#define MON_DAY_HOUR_MIN_SEC 2
#define ERROR "Invalid input, try again."

int main()
{
    char input[STR_MAX_LEN + 1] = {0};
    char *arraypointer = input;
    int temp[STR_MAX_LEN + 1] = {0};
    int *temppointer = input;
    int tempo = 0;
    printf("Enter a date in the format YYYY-MM-DD HH:mm:ss\n");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    for (int i = 0; i < YEAR; i++) // Checking the year
    {
        *(temppointer + i) = *(arraypointer + i);

        if (!isdigit(*(arraypointer + i)))
        {

            printf(ERROR);
            return 0;
        }
    }
    printf("%d", *(temppointer + 3));
    for (int i = 0; i < 4; i++)
    {
        tempo = *(temppointer + i);
    }
    printf("d\n", tempo);
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
    if (*(arraypointer + 7) != '-') // Checking the -
    {
        printf(ERROR);
        return 0;
    }
    for (int i = 0; i < MON_DAY_HOUR_MIN_SEC; i++) // Checking the day
    {

        if (!isdigit(*(arraypointer + i)))
        {
            printf(ERROR);
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