#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(void)
{
    int arrSize = 0;
    (void)printf("What size of memory to allocate to the array?\n");
    scanf("%d", &arrSize);
    int *ptr = (int *)calloc(arrSize, sizeof(int));

    if (ptr == NULL)
    {
        free(ptr);
        exit(1);
    }

    for (int i = 0; i < arrSize; i++)
    {
        *(ptr + i) = i + 1;
        (void)printf("%d\t", *(ptr + i));
    }
    (void)printf("\n");
    (void)printf("What size of memory to resize the array?\n");
    scanf("%d", &arrSize);
    ptr = (int *)realloc(ptr, sizeof(int));
    if (ptr == NULL)
    {
        free(ptr);
        exit(1);
    }

    for (int i = 0; i < arrSize; i++)
    {
        *(ptr + i) = i + 1;
        (void)printf("%d\t", *(ptr + i));
    }
    (void)printf("\n");
    free(ptr);
    ptr = NULL;

    return 0;
}
