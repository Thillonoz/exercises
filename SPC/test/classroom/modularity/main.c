#include "str.h"

int main(void)
{
    char string[STRING_MAX_LEN + 1] = "This is a string.";
    char string1[STRING_MAX_LEN + 1] = "This is an string."; // This is another string. What are you gonne do about it.

    (void)printf("The strings %s the same!\n", strComp(string, string1) ? "are" : "are not");
    (void)printf("The length of the string %hhu\n", secrets(string));

    return 0;
}
