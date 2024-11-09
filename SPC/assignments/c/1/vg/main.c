#include <stdio.h>
#include <stdint.h>

#define MIN_LEN 1
#define MAX_LEN 14
#define POLY 1100010110011001

int main(void)
{
    uint8_t arr[MAX_LEN] = {0};
    uint8_t temp = 0;

    for (size_t i = 0; i < MAX_LEN; i++)
    {
        arr[i] = i;
        printf("%hhd\t", arr[i]);
    }
    printf("\n");
    for (size_t i = 0, j = MAX_LEN; i < MAX_LEN; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        printf("%hhd\t", arr[i]);
    }
    printf("\n");

    return 0;
}