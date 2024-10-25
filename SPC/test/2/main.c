#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROWS 2U
#define COLUMNS 3U
#define ARGC 3

// A function to swap the values of two int variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct
{
    char name[8];
    unsigned int age;
} person_t;

int main(void)
{
    double var = 20;

    double *ptr = &var;

    double *tmp = ptr;

    double *nptr = NULL;

    // Address & values of the variables and the pointers
    (void)printf("%#p) %#p - %#p: %f - %f - %f\n", &ptr, ptr, &var, var, *ptr, *tmp);

    (void)printf("Size of ptr: %u bytes\n", sizeof(ptr)); // Size of a pointer to any type is fixed and it depends on the system architecture

    int x = 3, y = 4;
    swap(&x, &y); // Call by address
    (void)printf("x = %d and y = %d\n", x, y);

    person_t person = {.name = "Stefan", .age = 30};

    (void)printf("Size of person in the memory is %u bytes\n", sizeof(person));

    uint8_t *pptr = (uint8_t *)&person;

    // Get access to person byte by byte using a pointer
    for (uint8_t *cptr = pptr; (cptr - pptr) < sizeof(person); cptr++)
    {
        (void)printf("%#X\t", *cptr);
    }
    (void)printf("\n\n");

    // Get access to person byte by byte as an array
    for (uint8_t i = 0; i < sizeof(person); i++)
    {
        (void)printf("%#X\t", pptr[i]);
    }
    (void)printf("\n\n");

    char *argv[ARGC] = {"Hello", "World!", "123"};

    // Print argv using an index
    for (int i = 0; i < ARGC; ++i)
    {
        (void)printf("%d) %s\n", i + 1, argv[i]);
    }
    (void)printf("\n\n");

    // Print argv using a double pointer
    for (char **aptr = argv; (aptr - argv) < ARGC; ++aptr)
    {
        (void)printf("%d) %s\n", (aptr - argv) + 1, *aptr);
    }
    (void)printf("\n\n");

    // Print argv using a double and a single pointers
    for (char **aptr = argv; (aptr - argv) < ARGC; ++aptr)
    {
        (void)printf("%d) ", (aptr - argv) + 1);
        for (char *sptr = *aptr; *sptr != '\0'; sptr++)
        {
            printf("%c", *sptr);
        }
        (void)printf("\n");
    }

    person_t *stfn_ptr = &person;

    // Getting access to the members of a struct using an instance and a pointer to the instance
    (void)printf("\n%s is %u years old.\n", person.name, person.age);
    (void)printf("%s is %u years old.\n", (*stfn_ptr).name, stfn_ptr->age);

    int array[5] = {1, 2, 3, 4, 5};

    int *arrptr = array;

    *(arrptr + 1) = 20; // arrptr[1] = 20; &arrptr[1]

    (void)printf("array[1]: %d\n", array[1]);

    arrptr += 2;
    (void)printf("*arrptr: %d\n", *arrptr);

    arrptr--;
    (void)printf("*arrptr: %d\n", *arrptr);

    // arrptr is pointing to the second element

    (void)printf("*arrptr: %d\n", arrptr[1]); // arrptr[1] is equivalent to *(arrptr + 1)

    arrptr++;

    if (arrptr > array)
    {
        (void)printf("We have %u elements between array and arrptr.\n", arrptr - array);
    }

    int m = 20;
    int *const mptr = &m;

    const int n = 20;
    const int *nnptr = &n;

    // Error
    // *nnptr = 30;
    nnptr = NULL;

    const int o = 50;
    const int *const optr = &o;

    // Errors
    // optr = NULL;
    // *optr = 60;

    int matrix[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}};
    int(*qptr)[COLUMNS] = matrix;

    qptr++;
    (void)printf("matrix[1][1]: %d = %d\n", matrix[1][1], (*qptr)[1]); // Getting access to elements of a 2D array using a pointer

    return 0;
}
