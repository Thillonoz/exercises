#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int x = 15;
    int y = 25;
    int *a = &x;
    int *b = &y;
    swap(a, b);
    return 0;
}

void swap(int *x, int *y)
{
    (void)printf("Before the swap, these are the values (x, y in this scope)\n");
    (void)printf("Value of x: %d\nValue of y: %d\n", *x, *y);
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
    (void)printf("After the swap, this is now the values\n");
    (void)printf("Value of x: %d\nValue of y: %d\n", *x, *y);
}