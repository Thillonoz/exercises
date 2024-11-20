#include "utility.h"

// Function to print string
int printString(const char *string, uint8_t length)
{
    (void)printf("The unsorted string:\n");

    for (uint8_t i = 0; i < length; i++)
    {
        (void)printf("%c", string[i]);
    }
    (void)printf("\n");
    return 0;
}

int compareCharacters(char a, char b)
{
    if (tolower(a) == tolower(b))
    {
        return a - b;
    }

    return tolower(a) - tolower(b);
}

int strSort(char *str, uint8_t length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (compareCharacters(str[j], str[j + 1]) > 0)
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    return 0;
}

uint8_t lcm(uint8_t a, uint8_t b)
{
    uint8_t sumA = 0;
    uint8_t sumB = 0;
    uint8_t result = 0;

    for (uint8_t i = 2; i < a || i < b; i++)
    {
        sumA = a * i;
        sumB = b * i;
        if (sumA % a == 0 || sumB % b == 0)
        {
            if (sumA > sumB)
            {
                result = sumA;
            }
            else
            {
                result = sumB;
            }
            break;
        }
    }

    return result;
}

uint8_t gcd(uint8_t a, uint8_t b)
{
    return (a * b) / lcm(a, b);
}