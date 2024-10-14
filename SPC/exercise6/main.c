#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int randomNumber = rand();
    int randomNumber1 = rand();
    char input;
    printf("Input your lowercase letter to convert it to uppercase.\n");
    scanf("%c", &input);
    printf("This is your converted letter: %c\n", toupper(input));
    printf("Here's 2 random numbers generated :) \n%d %d\n", randomNumber, randomNumber1);
    return 0;
}