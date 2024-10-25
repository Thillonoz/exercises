#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define ARRAY_MAX 99

int main()
{
    srand(time(NULL));
    int arr[10] = {0};
    int *arrptr = arr;
    int temp = 0;

    printf("The unsorted numbers: \n");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        *(arrptr + i) = rand() % 100;
        printf("%d\t", *(arrptr + i));
    }

    for (int i = 0; i <= ARRAY_SIZE; i++)
    {
        for (int j = ARRAY_SIZE; j >= 0; j--)
        {
            if (*(arrptr + i) > *(arrptr + j))
            {
                temp = *(arrptr + j);
                *(arrptr + j) = *(arrptr + i);
                *(arrptr + i) = temp;
            }
        }
    }

    printf("\nThe sorted numbers: \n");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {

        printf("%d\t", *(arrptr + i));
    }

    return 0;
}