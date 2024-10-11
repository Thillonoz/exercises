#include <stdio.h>
#include <string.h>

struct car
{
    char brand[10];
    char model[10];
    char color[10];
} car1;

struct date
{
    int year;
    int month;
    int day;
    char person[20];
    struct car car1;
} christmas;

int main()
{
    christmas.year = 2024, christmas.month = 12, christmas.day = 24;
    strcpy(christmas.car1.brand, "Volvo");
    strcpy(christmas.car1.model, "V70");
    strcpy(christmas.car1.color, "Silver");

    strcpy(christmas.person, "Santa Claus");
    printf("%04d-%02d-%02d\nAnd who comes that day? %s\n", christmas.year, christmas.month, christmas.day, christmas.person);
    printf("And he's gonna drive a %s %s %s\n", christmas.car1.color, christmas.car1.brand, christmas.car1.model);
    return 0;
}