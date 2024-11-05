#include <stdio.h>

#define ARRAY_SIZE 10
#define BIG_ARRAY 20

void bubbleSort(int arr[ARRAY_SIZE]);
void doubleSort(int arr[ARRAY_SIZE]);

int main(void)
{
    int array[ARRAY_SIZE] = {64, 4, 5, 43, 77, 2, 99, 32, 54, 6};
    int array1[ARRAY_SIZE] = {56, 45, 23, 1, 7, 9, 87, 88, 11, 80};
    int array2[BIG_ARRAY];
    bubbleSort(array);
    bubbleSort(array1);
    for (int i = 0; i <= ARRAY_SIZE - 1; i++)
    {
        array2[i] = array[i];
    }
    int j = 0;
    for (int i = ARRAY_SIZE; i <= BIG_ARRAY - 1; i++)
    {

        array2[i] = array1[j];
        j++;
    }
    doubleSort(array2);
    for (int i = 0; i < BIG_ARRAY - 1; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
    return 0;
}

void bubbleSort(int arr[ARRAY_SIZE])
{
    int temp = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void doubleSort(int arr[BIG_ARRAY])
{

    int temp = 0;
    for (int i = 0; i < BIG_ARRAY - 1; i++)
    {
        for (int j = 0; j < BIG_ARRAY - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}