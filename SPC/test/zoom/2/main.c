#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[6] = "hello";
    char result[100] = "";

    FILE *text = fopen("text.txt", "r");
    if (text == NULL)
    {
        printf("Failed to find the file\n");
        exit(1);
    }
    while (fgets(result, 100, text))
    {
        if (strstr(result, string) != NULL)
        {
            printf("Found the word, this is the whole line:\n%s", result);
        }
    }

    if (EOF == fclose(text))
    {
        printf("Failed to close the file\n");
        exit(1);
    }

    return 0;
}