#include <stdio.h>

int main()
{
    char array[20];
    char arrayReverse[20];

    printf("Please input a string to get it in reverse. ");
    // scanf("%s", &array);
    while (getchar() != '\n')
        ;

    int count = sizeof(array) - 1;
    printf("%d", count);
    /*for (int i = 0; i < sizeof(array) - 1; i++)
    {
        arrayReverse[i + sizeof(array) - 1] = array[i];
    }

    printf("%s\n", array);
    printf("%s\n", arrayReverse);*/

    return 0;
}