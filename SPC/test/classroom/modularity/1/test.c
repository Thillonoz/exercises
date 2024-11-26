#include <stdio.h>

int main(void)
{
    int x = 3;
    printf("%d, %d, %d, %d\n", x++, x, ++x, x);
    return 0;
}