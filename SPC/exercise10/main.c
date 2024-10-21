#include <stdio.h>

int main()
{
    int input = 0;
    int valid = 1;
    int binArray[9];
    for (int i = 0; i < 10; i++)
    {
        binArray[i] = 0;
    }

    printf("Input a number 0-255: \n");
    scanf("%d", &input);

    if (input < 0 || input > 255)
    {
        printf("Input a number 0-255: \n");
        scanf("%d", &input);
    }

    for (int i = 0; input > 0; i++)
    {
        binArray[i] = input % 2;
        input = input / 2;
    }
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", binArray[i]);
    }
    printf("\n");

    return 0;
}