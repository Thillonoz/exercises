#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 10
#define MATRIX_SIZE 3
int array[MAX_ARR_SIZE] = {0};
int array2d[MATRIX_SIZE][MATRIX_SIZE] = {0};
void randomNumbers(int *array);

int main(void)
{
    randomNumbers(array);
    return 0;
}

void randomNumbers(int *array)
{
    srand(time(NULL));
    // This is where the random numbers are getting generated and stored in the array
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
        // This is where I check the number just generated so it doesn't match any other in the array, creating a new one if it finds it already in the array
        for (int j = 0; j < MAX_ARR_SIZE; j++)
        {
            if (array[j] == array[i])
            {
                array[i] = rand() % 100;
            }
        }
        (void)printf("%d\t", array[i]);
    }
    (void)printf("\n");
}