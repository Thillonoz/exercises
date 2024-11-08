#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define the correct format
#define FORMAT "YYMMDD-NNNN"
#define PERS_NUM_LEN 10
#define INPUT_LEN 11

bool checkPersonalNumber(int personNummer[]);

int main(void)
{
    char input[INPUT_LEN];
    int year, month, day, serial; // Variables to seperate the input
    int correct = 0;              // Flag to check if input is valid
    int userInput[INPUT_LEN];
    bool result = false;

    (void)printf("Please input your personnummer (YYMMDD-NNNN): \n");

    printf("Enter date in format YYMMDD-NNNN: ");
    scanf("%s", &input);

    // Use sscanf to parse the input
    if (sscanf(input, "%2d%02d%02d-%4d", &year, &month, &day, &serial) == 4)
    {

        // Additional checks for valid month and day ranges
        if (month < 1 || month > 12 || day < 1 || day > 31)
        {
            printf("Invalid date. Please try again.\n");
            // Clear any remaining characters in the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            return 0;
        }

        // This is to make an array that converts from the ascii representation to digits using - '0'
        for (int i = 0; i <= PERS_NUM_LEN; i++)
        {
            userInput[i] = input[i] - '0';
        }
        printf("\n");

        // call to function checking input
        result = checkPersonalNumber(userInput);

        // display output

        printf("It's %s match!\n", result == true ? "a" : "not a");

        printf("\n");

        return 0;
    }
    else
    {
        printf("Incorrect input, try again (YYMMDD-NNNN)\n");
    }
}
// The function to do the arithmetic for finding the check digit
bool checkPersonalNumber(int personNummer[])
{
    int firstDigit = 0;
    int secondDigit = 0;
    int checkDigit = 0;
    int temp = 0;
    int arrTemp[PERS_NUM_LEN];
    for (int i = 0; i < PERS_NUM_LEN; i++)
    {
        if (i >= 6)
        {
            arrTemp[i] = personNummer[i + 1];
            continue;
        }

        arrTemp[i] = personNummer[i];
    }

    for (int i = 0; i < PERS_NUM_LEN - 1; i++)
    {
        // Arithmetic for the PIN

        if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8)
        {
            temp = arrTemp[i] * 2;
        }
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            temp = arrTemp[i] * 1;
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

    checkDigit = (10 - (checkDigit % 10)) % 10;

    if (checkDigit == arrTemp[PERS_NUM_LEN - 1])
    {
        return true;
    }
    else
    {
        return false;
    }
}