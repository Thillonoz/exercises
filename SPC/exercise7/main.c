#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} date_t;

int main()
{
    date_t day1 = {7, 8, 1992};

    printf("%d-%02d-%02d\n", day1.year, day1.month, day1.day);
    return 0;
}