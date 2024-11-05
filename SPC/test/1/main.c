#include <stdio.h>

#define MAX_STR_LEN 50
int strLen(char *strptr);

int main(void)
{
    char string[MAX_STR_LEN];
    printf("Type your string here.\n");
    // scanf("%s", &string);
    fgets(string, MAX_STR_LEN, stdin);

    char *strptr;
    strptr = string;

    int length = strLen(strptr);
    printf("%d\n", length);
    return 0;
}
int strLen(char *strptr)
{
    int i = 0;
    while (strptr[i] != '\0')
    {
        i++;
    }
    return i - 1; //Return i - 1 to get rid of the newline character
}