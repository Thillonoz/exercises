#include <stdio.h>

int main(void)
{
    FILE *file = fopen("story.txt", "r");
    int count = 1;
    (void)printf("%d ", count);
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            count++;
            (void)printf("\n%d ", count);
            continue;
        }
        putchar(c);
    }
    (void)printf("\n");
    return 0;
}