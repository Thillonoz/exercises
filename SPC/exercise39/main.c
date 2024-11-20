
#include "utility.h"

int main()
{
    uint8_t a = 8;
    uint8_t b = 12;

    char string[STRING_MAX_LEN + 1] = "jkdlsADJayutuBBVvngjgUtU";
    uint8_t length = strlen(string);
    assert(0 == printString(string, length));
    (void)printf("Print string... Passed\n\n");

    assert(0 == strSort(string, length));
    (void)printf("Sort string... Passed\n\n");

    assert(0 == printString(string, length));
    (void)printf("Print string... Passed\n\n");

    (void)printf("The least common multiple of %hhu and %hhu is %hhu\n", a, b, lcm(a, b));

    (void)printf("The greatest common divisor for %hhu and %hhu is %hhu\n", a, b, gcd(a, b));

    return 0;
}