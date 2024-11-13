#include <stdio.h>
void splitString(char str, char delim);
int main(void)
{
    char string[100];
    char delimeter;
    (void)printf("What is the string you want to split?");
    scanf("%s", string);
    (void)printf("And how do you want to split it?");
    scanf("%c", &delimeter);
    splitString(string, delimeter);
    return 0;
}

void splitString(char str, char delim)
{
    printf("%s", str);
}