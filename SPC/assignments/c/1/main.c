#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the correct format
#define FORMAT "YYYYMMDD-NNNN"
#define PERS_NUM_LEN 10

bool checkPersonalNumber(int *personNummer);

int main(void)
{
    // Hardcode the number at first
    int userInput[PERS_NUM_LEN] = {9, 2, 0, 8, 0, 7, 0, 7, 1, 5};
    int doubleCheck[PERS_NUM_LEN] = {8, 1, 1, 2, 1, 8, 9, 8, 7, 6};
    int sofia[PERS_NUM_LEN] = {9, 1, 0, 5, 1, 0, 2, 3, 2, 2};

    char input[PERS_NUM_LEN];

    // printf("Please input your personnummer (YYYYMMDD-NNNN): \n");
    // fgets(input, sizeof(input), stdin);
    // if (10 == sscanf(input, "%d%d%d%d%d%d-%d%d%d%d", &userInput))
    // {
    //     printf("Yes");
    // }
    // else
    // {
    //     printf("No");
    // }

    bool result = false;
    printf("To check the array ");
    for (int i = 0; i < PERS_NUM_LEN; i++)
    {
        printf("%d", userInput[i]);
    }
    printf("\n");
    // Arithmetic for checking the personnummer

    /*          THIS IS TO CHECK THE ARRAY IF IT'S WHAT'S EXPECTED
        printf("To check if the array is changed to what's expected ");
        for (int i = 0; i < PERS_NUM_LEN ; i++)
        {
            printf("%d", personNummer[i]);
        }

        printf("\n");
    */

    // sscanf for formatted input
    // call to function checking input
    result = checkPersonalNumber(userInput);
    // display output

    printf("It's %s match!\n", result == true ? "a" : "not a");

    printf("\n");

    return 0;
}
// The function to do the arithmetic for finding the check digit
bool checkPersonalNumber(int *personNummer)
{
    int firstDigit = 0;
    int secondDigit = 0;
    int checkDigit = 0;
    int temp = 0;
    for (int i = 0; i < PERS_NUM_LEN - 1; i++)
    {
        // Arithmetic for the PIN
        if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8)
        {
            temp = *(personNummer + i) * 2;
        }
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            temp = *(personNummer + i) * 1;
        }
        // Arithmetic for the check digit
        if (temp >= 10)
        {
            firstDigit = temp / 10;
            secondDigit = temp % 10;
            checkDigit += firstDigit + secondDigit;
        }
        else
        {
            checkDigit += temp;
        }
    }
    /*for (int i = 0; i < PERS_NUM_LEN - 1; i++) // Using one less of the array to exclude the check digit
    {
        if (*(personNummer + i) >= 10)
        {
            firstDigit = *(personNummer + i) / 10;
            secondDigit = *(personNummer + i) % 10;
            checkDigit += firstDigit + secondDigit;
        }
        else
        {
            checkDigit += *(personNummer + i);
        }
    }*/

    checkDigit = (10 - (checkDigit % 10)) % 10;
    if (checkDigit == *(personNummer + PERS_NUM_LEN - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}