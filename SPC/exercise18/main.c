#include <stdio.h>

#define SIZE_OF_ARRAY 3
#define SIZE_OF_MATRIX 9

int main()
{
    int arr[3][3];
    int count = sizeof(arr) / sizeof(arr[0][0]);
    int j = 0;
    int i = 0;
    for (i = 0; i < SIZE_OF_MATRIX; i++)
    {
        printf("Please input every element of this 2D array:\n");
        scanf("%d", &arr[j][i]);
    }
    i = 0;
    for (int l = 0; l < SIZE_OF_ARRAY; l++, i++)
    {
        for (int k = 0; k < SIZE_OF_ARRAY; k++)
        {
            printf("%d\t", arr[l][k]);
        }
        printf("\n");
    }

    return 0;
}