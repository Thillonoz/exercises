#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    srand(time(0));
    int guess = 0;
    char gameState = 'y';

    int validInput = 0;

    int randomNum = rand() % 100;
    while (gameState == 'y')
    {
        int numGuesses = 10;
        int randomNum = rand() % 100;
        printf("****************************\n");
        printf("*******Guessing game.*******\n");
        printf("****************************\n");
        for (int i = numGuesses; i > 0; i--)
        {
            if (numGuesses > 1)
            {
                printf("You have %d guesses left.\n", numGuesses);
            }
            else
            {
                printf("You have %d guess left.\n", numGuesses);
            }
            printf("Guess a number from 0-99: ");
            scanf("%d", &guess);

            if (guess == randomNum)
            {
                printf("\nCongratulations!! You guessed correctly!\n");
                break;
            }
            else if (guess != randomNum && numGuesses == 1)
            {
                printf("\nSorry you didn't get it and you're out of guesses.\n");
            }
            else
            {
                if (guess / randomNum < 1.0)
                {
                    printf("Too small number.\n\n");
                }
                else
                {
                    printf("Too big number.\n\n");
                }
                numGuesses--;
            }
        }
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &gameState);
    }
    return 0;
}
