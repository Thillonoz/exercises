#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    uint8_t age;
} person_t;

static void free_person(person_t **person);
static person_t *create_person(const char *name, uint8_t age);

int main(void)
{
    int length;
    (void)printf("Enter the length of the array: ");
    scanf("%d", &length);
<<<<<<< HEAD
    person_t *ptr 
=======

    person_t *person = (person_t *)malloc(sizeof(person_t));

    printf("What's the person's name?\n");
    scanf("%s", (person)->name);

    printf("What's the person's age?\n");
    scanf("%u", (person)->age);

    create_person(person->name, person->age);
    if (person == NULL)
    {
        printf("Failed to create Stefan\n");
        exit(1);
    }
    printf("%s is %u years old.\n", person->name, person->age);

    free_person(&person);
>>>>>>> f6d13c564ec148e11fbd5e9863f1b52f93ea6723

    return 0;
}

static void free_person(person_t **person)
{
    free((*person)->name);
    free(*person);
    *person = NULL;
}

static person_t *create_person(const char *name, uint8_t age)
{
    person_t *ptr = (person_t *)malloc(sizeof(person_t));
    if (ptr != NULL)
    {
        ptr->age = age;
        size_t len = strlen(name) + 1;
        ptr->name = (char *)malloc(len * sizeof(char));
        if (ptr->name != NULL)
        {
            strncpy(ptr->name, name, len);
        }
        else
        {
            free(ptr);
            ptr = NULL;
        }
    }

    return ptr;
}