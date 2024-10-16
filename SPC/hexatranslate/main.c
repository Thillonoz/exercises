#include <stdio.h>

int main(void)
{
    int input = 0;
    int validInput = 0;
    while (1)
    {
        printf("Input your number to convert to hexadecimal: ");
        validInput = scanf("%d", &input);

        if (validInput == 1)
        {
            printf("%x\n", input);
            break;
        }
        else
        {
            printf("Wrong input, please input an integer.\n");
            while (getchar() != '\n')
                ;
        }
    }
    return 0;
}