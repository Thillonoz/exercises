#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define FORMAT "YYMMDD-NNNN" // Define the correct format
#define PERS_NUM_LEN 10      // The number of digits in a swedish personnummer
#define INPUT_LEN 11         // It's one more than the personnummer to accomodate for the '-' character

// Define year, month and day min-max range to prevent incorrect input
#define YEAR_MIN 47 // 1947 was the first year with swedish personnummer
#define MONTH_MIN 1
#define MONTH_MAX 12
#define DAY_MIN 1
#define DAY_MAX 31

void clearBuffer(void);
bool checkPersonalNumber(const int *personNummer);

int main(void)
{
    char input[INPUT_LEN];
    int year, month, day, serial; // Variables to seperate the input
    int parsedInput[INPUT_LEN];
    bool result = false;

    // Prompt the user about what the program is about and what's expected as an input
    (void)printf("Please input your personnummer (%s) to check if it's valid: \n", FORMAT);
    scanf("%s", &input);

    // Use sscanf to parse the input
    if (sscanf(input, "%2d%02d%02d-%4d", &year, &month, &day, &serial) == 4)
    {

        // Check for valid month and day ranges
        if (year < YEAR_MIN)
        {
            (void)printf("Invalid date. Please try again. (%s)\n", FORMAT);
            clearBuffer();
        }

        if (month < MONTH_MIN || month > MONTH_MAX || day < DAY_MIN || day > DAY_MAX)
        {
            (void)printf("Invalid date. Please try again. (%s)\n", FORMAT);
            // Clear any remaining characters in the input buffer
            clearBuffer();

            return 0;
        }

        // This loop is converting what the user put in as char and making it int
        // and converts the ascii representation of the input by subtracting '0' from each element
        for (int i = 0; i < INPUT_LEN; i++)
        {
            parsedInput[i] = input[i] - '0';
        }
        (void)printf("\n");

        // Call to the function checking input
        result = checkPersonalNumber(parsedInput);

        // Display the result of the check

        (void)printf("It's %s match!\n", result == true ? "a" : "not a");

        (void)printf("\n");

        return 0;
    }
    else
    {
        printf("Incorrect input, try again (%s)\n", FORMAT);
    }
}
void clearBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// The function to do the arithmetic for finding the check digit
bool checkPersonalNumber(const int *personNummer)
{
    int checkDigit = 0;
    int product = 0;

    for (int i = 0, j = 0; i < PERS_NUM_LEN - 1; i++, j++)
    {
        if (i == 6) // Skip the '-'
        {
            j++;
        }

        // Arithmetic for the PIN, alternate multiply by 2 and 1
        product = (i % 2 == 0) ? personNummer[j] * 2 : personNummer[j];

        // Add digits for numbers >= 10
        checkDigit += (product >= 10) ? product / 10 + product % 10 : product;
    }

    // Calculate the check digit
    checkDigit = (10 - (checkDigit % 10)) % 10;

    return (checkDigit == personNummer[PERS_NUM_LEN]);
}