#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int arrLength);

int main()
{
    srand(time(NULL));
    int unsorted[10];
    int randomNumber = rand() % 100 + 1;
    for (int i = 0; i < 10; i++)
    {

        randomNumber = rand() % 100 + 1;
        unsorted[i] = randomNumber;
    }

    int arrLength = (sizeof(unsorted) / sizeof(unsorted[0]));

    bubbleSort(unsorted, arrLength);

    for (int i = 0; i <= arrLength - 2; i++)
    {
        printf("%d, ", unsorted[i]);
    }
    printf("%d.\n", unsorted[9]);

    return 0;
}

void bubbleSort(int arr[], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        for (int j = 0; j < arrLength - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}