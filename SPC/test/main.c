#include <stdio.h>

#define MAX_STR_LEN 25

void foo(char string[MAX_STR_LEN]);

int main(void)
{

    char string[MAX_STR_LEN] = "Hello world.";
    foo(string);

    return 0;
}

void foo(char string[MAX_STR_LEN])
{
    for (int i = 0; i < MAX_STR_LEN; i++)
    {
        (void)printf("%c", string[i]);
    }
    (void)printf("\n");
}