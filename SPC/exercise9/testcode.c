#include <stdio.h>

int main()
{
    int arr[99];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
        printf("%d\n", arr[i]);
    }

    return 0;
}