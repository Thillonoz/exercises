#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter a date in the format YYYY-MM-DD HH:mm:ss");
    scanf("%s", &input);

    for (int i = 0; i < strlen(input); i++)
    {
        printf("%c", input[i]);
    }

    return 0;
}