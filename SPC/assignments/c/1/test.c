#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 13 // Expected length of personnummer in format "YYMMDD-nnnC"

int calculate_control_digit(const char *personnummer)
{
    int multipliers[] = {2, 1}; // Alternating multipliers 2 and 1
    int sum = 0;
    int multiplier_index = 0;

    for (int i = 0; i < 10; i++)
    {
        int digit = personnummer[i] - '0'; // Convert char to int
        if (i == 6)
            i++; // Skip the dash ('-') at position 6

        int product = digit * multipliers[multiplier_index];
        multiplier_index = 1 - multiplier_index; // Alternate between 2 and 1

        // If product > 9, split the digits and sum them
        if (product > 9)
        {
            sum += (product / 10) + (product % 10);
        }
        else
        {
            sum += product;
        }
    }

    // Calculate control digit
    int control_digit = (10 - (sum % 10)) % 10;
    return control_digit;
}

int is_valid_format(const char *personnummer)
{
    // Check if length matches
    if (strlen(personnummer) != LENGTH)
        return 0;

    // Check specific positions for digits and dash
    for (int i = 0; i < LENGTH; i++)
    {
        if (i == 6)
        {
            if (personnummer[i] != '-')
                return 0;
        }
        else
        {
            if (!isdigit(personnummer[i]))
                return 0;
        }
    }
    return 1;
}

int main()
{
    char personnummer[LENGTH + 1];

    printf("Enter a Swedish personnummer (YYMMDD-nnnC): ");
    scanf("%s", personnummer);

    // Validate format
    if (!is_valid_format(personnummer))
    {
        printf("Invalid format!\n");
        return 1;
    }

    // Calculate control digit
    int calculated_control_digit = calculate_control_digit(personnummer);
    int entered_control_digit = personnummer[12] - '0'; // Last character is control digit

    // Compare control digits
    if (calculated_control_digit == entered_control_digit)
    {
        printf("The personnummer is valid.\n");
    }
    else
    {
        printf("The personnummer is invalid.\n");
    }

    return 0;
}