#include <string.h>
#include "str.h"

#if !defined(STRING_MAX_LEN) || (STRING_MAX_LEN < 8) || (STRING_MAX_LEN > 64)
#error PERSON_NAME_MAX_LEN shall be defined as an integer in the range of 8 and 64
#endif

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

bool strComp(const char *string, const char *string1)
{
    uint8_t firstString = strLeng(string);
    uint8_t secondString = strLeng(string1);
    bool status = true;
    uint8_t leng = strLeng(string);
    if (string != NULL || string1 != NULL)
    {

        if (firstString == secondString)
        {
            for (size_t i = 0; i < STRING_MAX_LEN; i++)
            {
                if (*(string + i) != *(string1 + i))
                {
                    status = false;
                }
            }
        }
        else
        {
            status = false;
        }
    }
    return status;
}

uint8_t secrets(const char *string)
{
    return strLeng(string);
}
