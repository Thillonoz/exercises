#include <stdio.h>
#include <stdint.h>

void *split_string(const char *str, const char delim);

int main(void)
{
    char string[100] = "String that, needs-to/be.split. That's,right,it's-a lot/of/delimeters";
    char delim = '/';
    (void)printf("This is the string before splitting:\n%s\n", &string);

    (void)printf("This is the string after splitting:\n");
    split_string(string, delim);

    return 0;
}

void *split_string(const char *str, const char delim)
{
    char resultString[sizeof(str)] = {'0'};
    uint8_t i = 0;

    while (*(str + i) != '\0')
    {

        if (*(str + i) == delim)
        {
            (void)printf("\n");
            (void)printf("%c", *(str + i));
        }
        else
        {
            (void)printf("%c", *(str + i));
        }
        i++;
    }
}
