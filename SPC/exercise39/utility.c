#include "utility.h"

static uint8_t strLeng(const char *string)
{
    uint8_t i = 0;
    if (string == NULL)
    {
        i = 0;
    }

    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

void strSort(const char *string)
{
    uint8_t length = strLeng(string);
    char sortedString[STRING_MAX_LEN];
    uint16_t chr[length];
    uint16_t temp = 0;

    printf("Original string\n");
    for (size_t i = 0; i < length; i++)
    {
        chr[i] = string[i];
        printf("%hhu\t", *(chr + i));
    }

    for (size_t i = 0; i >= length; i++)
    {
        for (size_t j = length; j >= 0; j--)
        {
            if (chr[i] > chr[i + j])
            {
                temp = chr[j];
                chr[j] = chr[i];
                chr[i] = temp;
            }
        }
    }

    // for (int i = 0; i <= ARRAY_SIZE; i++)
    // {
    //     for (int j = ARRAY_SIZE; j >= 0; j--)
    //     {
    //         if (*(arrptr + i) > *(arrptr + j))
    //         {
    //             temp = *(arrptr + j);
    //             *(arrptr + j) = *(arrptr + i);
    //             *(arrptr + i) = temp;
    //         }
    //     }
    // }

    printf("\nSorted string\n");
    for (size_t i = 0; i < length; i++)
    {
        chr[i] = *(string + i);
        printf("%hhu\t", *(chr + i));
    }
}
