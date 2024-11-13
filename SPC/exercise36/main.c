#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    uint8_t age;
} person_t;

int main(void)
{
    int length;
    (void)printf("Enter the length of the array: ");
    scanf("%d", &length);
    int arrLen[length];

    return 0;
}