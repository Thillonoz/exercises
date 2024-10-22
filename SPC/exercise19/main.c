#include <stdio.h>
#include <ctype.h>

int main()
{
    char arr[50];

    printf("Input text: \n");
    fgets(arr, 50, stdin);

    printf("%d \n", arr[14]);
    return 0;
}