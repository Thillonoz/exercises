#include <stdio.h>
#include <string.h>

int main()
{
    char array[20];
    char arrayReverse[20];
    int stringLength = 0;
    printf("Please input a string to get it in reverse: ");
    scanf("%s", &array);

    stringLength = strlen(array);
    int j = stringLength - 1;
    for (int i = 0; i < stringLength; i++)
    {

        arrayReverse[i] = array[j];
        j--;
    }

    printf("Reversed string: ");
    printf("%s\n", arrayReverse);

    return 0;
}