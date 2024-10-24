#include <stdio.h>
#include <string.h>

int main(void)
{
    int var = 5;
    int *point = &var;
    int **ptr = &point;

    printf("Value of var: %d\n", var);
    printf("Address of var: %p\n", &var);
    printf("Value of pointer: %d\n", *point);
    printf("Address of pointer: %p\n", &point);
    printf("Value of pointer-pointer: %d\n", **ptr);
    printf("Address of pointer-pointer: %p\n", &ptr);

    printf("Size of var: %d\n", sizeof(var));
    printf("Size of pointer: %d\n", sizeof(*point));
    printf("Size of pointer-pointer: %d\n", sizeof(**ptr));

    return 0;
}
