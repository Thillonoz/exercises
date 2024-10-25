#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY 3

int main()
{
    srand(time(NULL));
    int arr[2][3] = {1, 2, 3, 6, 7, 8};
    int(*point)[3] = arr;

    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        (*point)[i] = rand() % 100;
    }
    point++;
    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        (*point)[i] = rand() % 100;
    }
    point--;
    printf("Your table looks like: \n");
    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {

        printf("%d\t", (*point)[i]);
    }
    printf("\n");
    point++;
    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {

        printf("%d\t", (*point)[i]);
    }

    return 0;
}