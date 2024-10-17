#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    /*int arr[99];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
        printf("%d\n", arr[i]);
    }*/
    srand(time(0));
    int guess;
    int numGuesses = 10;
    int playGame = 1;
    int randomNum = rand() % 100;
    char gameState;
    printf("**************************\n");
    printf("*******Game started*******\n");
    printf("**************************\n");
    do
    {

        if (numGuesses > 1)
        {
            printf("You have %d guesses left.\n", numGuesses);
        }
        else
        {
            printf("You have %d guess left.\n", numGuesses);
        }
        printf("Guess a number.");
        if (1 == scanf("%d", &guess))
        {
            if (guess < 0 || guess > 99)
            {
                printf("Invalid input, please input a number between 0-99.\n");
                getchar();
                continue;
            }
            if (guess == randomNum)
            {
                printf("\nCongratulations!! You guessed correctly!\n");
                printf("Do you want to play again? (y/n)\n");
                scanf(" %c", &gameState);
                if (gameState == 'n')
                {
                    return 0;
                }
                numGuesses = 10;
                randomNum = rand() % 100;
                printf("**************************\n");
                printf("*******Game started*******\n");
                printf("**************************\n");
            }
            else if (guess != randomNum && numGuesses == 1)
            {
                printf("\nSorry you didn't get it and you're out of guesses.\n");
                printf("Do you want to play again? (y/n)\n");
                scanf(" %c", &gameState);
                if (gameState == 'n')
                {
                    return 0;
                }
                numGuesses = 10;
                randomNum = rand() % 100;
                printf("**************************\n");
                printf("*******Game started*******\n");
                printf("**************************\n");
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

        else
        {
            printf("Invalid input, please input a number.\n");
            getchar();
        }

    } while (playGame == 1 && numGuesses >= 0);

    return 0;
}