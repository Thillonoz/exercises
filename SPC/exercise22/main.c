#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STR_MAX_LEN 50

int main()
{
    char string[STR_MAX_LEN + 1] = {0};
    char *stringptr = string;

    printf("Enter a string: ");
    fgets(string, STR_MAX_LEN, stdin);

    int len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        if (islower(*(stringptr + i)))
        {
            *(stringptr + i) = toupper(*(stringptr + i));
        }
        else
        {
            *(stringptr + i) = tolower(*(stringptr + i));
        }
    }

    for (int i = 0; i < len; i++)
    {
        printf("%c", *(stringptr + i));
    }
    return 0;
}