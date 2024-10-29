#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_SIZE 10

int *randomNumbers(void);
void bubbleSort(uint8_t unsorted);

int main()
{
    int arr[10] = {0};
    srand(time(NULL));
    *arr = *randomNumbers();
    for (int i = 0; i < ARRAY_SIZE; i++)
    {

        (void)printf("%d\t", arr[i]);
    }
    (void)printf("\n");
    return 0;
}

int *randomNumbers(void)
{

    int arr[10] = {0};
    // uint8_t random = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int random = rand() % 100;
        arr[i] = random;
        (void)printf("%d\t", arr[i]);
    }
    (void)printf("\n");
}