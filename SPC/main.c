#include <stdio.h>
#include <stdint.h>

void swap(uint8_t *x, uint8_t *y);

int main(void)
{
    uint8_t *a = 15;
    uint8_t *b = 25;
    swap(*a, *b);
    return 0;
}

void swap(uint8_t *x, uint8_t *y)
{
    (void)printf("Before the swap, these are the values of var (x in this scope), and var1 (y in this scope).\n");
    (void)printf("Value of x: %u\nValue of y: %u\n", x, y);
    uint8_t temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
    (void)printf("After the swap, this is now the values\n");
    (void)printf("Value of x: %u\nValue of y: %u\n", x, y);
}