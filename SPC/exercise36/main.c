#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    uint8_t age;
} person_t;

static void free_persons(person_t **persons, uint8_t length);

int main(void)
{
    uint8_t length;
    (void)printf("Enter the number of persons: ");
    scanf("%u", &length);

    person_t *persons = (person_t *)malloc(length * sizeof(person_t));
    if (persons == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        char buffer[100];
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", buffer);
        // Allocate memory for the name and copy the input
        persons[i]
            .name = (char *)malloc(strlen(buffer) + 1);
        if (persons[i].name == NULL)
        {
            printf("Memory allocation failed for name.\n");
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++)
            {
                free(persons[j].name);
            }
            free(persons);
            return 1;
        }
        strcpy(persons[i].name, buffer);

        printf("Enter age of person %d: ", i + 1);
        scanf("%d", &persons[i].age);
    }

    // Print all persons
    printf("\nList of Persons:\n");
    for (int i = 0; i < length; i++)
    {
        printf("Person %d: Name = %s, Age = %d\n", i + 1, persons[i].name, persons[i].age);
    }
    // Free all allocated memory
    for (int i = 0; i < length; i++)
    {
        free(persons[i].name);
    }
    free(persons);

    return 0;
}

static void free_persons(person_t **persons, uint8_t length)
{
    // Free all allocated memory
    for (size_t i = 0; i < length; i++)
    {
        free(persons);
    }
    free(persons);
}
