#include <stdio.h>

int main()
{
    int height = 0;
    printf("You decide the height of the christmas tree!\n");
    scanf("%d", &height);

    printf("  *\n *** \n*****\n");
    for (int i = 0; i < height; i++)
    {
        printf("  *\n");
    }

    return 0;
}