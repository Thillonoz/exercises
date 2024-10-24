#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int var[5] = {1, 2, 3, 4, 5};
int main(void)
{
    int *ptr = var;
    printf("\nOriginal elements, printed.\n");
    for (int i = 0; i < (sizeof(var) / sizeof(var[0])); i++)
    {
        printf("%d ", var[i]); // Show the elements in the array
    }
    printf("\nModified elements, printed.\n");
    for (int i = 0; i < (sizeof(var) / sizeof(var[0])); i++)
    {
        *(ptr + i) = 20;     // Modify the elements
        printf("%d ", *ptr); // Print the new elements
    }

    return 0;
}
