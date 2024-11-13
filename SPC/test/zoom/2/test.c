#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *split_string(const char *str, const char delim);

int main()
{
    char string[35] = "hello, this is the string to split";
    char delimeter = ' ';
    char *token;

    (void)printf("Original string: %s\n", string);

    token = split_string(string, delimeter);

    while (token != NULL)
    {
        (void)printf("%s\n", token);
        token = split_string(NULL, delimeter);
    }
    return 0;
}

static char *split_string(const char *str, const char delim)
{
    static const char *current;
    static char buffer[256];
    static int stringLen = sizeof(str);

    if (str != NULL)
    {
        current = str;
    }

    if (current == NULL || *current == '\0')
    {
        return NULL;
    }

    const char *delim_pos = strchr(current, delim);
    int length;

    if (delim_pos != NULL)
    {

        length = delim_pos - current;
    }
    else
    {

        length = strlen(current);
    }

    strncpy(buffer, current, length);
    buffer[length] = '\0';

    current = (delim_pos != NULL) ? delim_pos + 1 : NULL;

    return buffer;
}