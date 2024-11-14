#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *ptr = (int *)malloc(10 * sizeof(int));
    if (ptr == NULL)
    {
        free(ptr);
        ptr = NULL;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", ptr[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", ptr[i]);
    }
    printf("\n");
    free(ptr);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", ptr[i]);
    }
    ptr = NULL;

    return 0;
}