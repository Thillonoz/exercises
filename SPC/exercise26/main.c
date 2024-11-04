/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <string.h>
#define NAME_LEN 16
typedef struct
{

    int age;

    float height;

    char name[NAME_LEN];

} person_t;

static person_t get_person(void);

int main()
{
    person_t new_person = get_person();
    printf("\nPerson Details:\n");
    printf("Name: %s\n", new_person.name);
    printf("Age: %d\n", new_person.age);
    printf("Height: %.2f meters\n", new_person.height);

    return 0;
}

static person_t get_person(void)
{
    person_t person;
    char input = 0;
    printf("Enter name (max %d characters): ", NAME_LEN - 1);
    fgets(person.name, NAME_LEN, stdin);
    size_t length = strlen(person.name);
    if (length > 0 && person.name[length - 1] == '\n')
    {
        person.name[length - 1] = '\0';
    }

    printf("Enter age: ");
    scanf("%d", &person.age);

    printf("Enter height in meters: ");
    scanf("%f", &person.height);
    return person;
}