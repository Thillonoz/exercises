#include <stdio.h>
#include <math.h>
#include <stdint.h>

int primePrint(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    uint8_t m = 23;
    uint8_t n = 243;
    for (int i = m; i < n; i++)
    {
        if (primePrint(i))
        {
            /* code */
        }

        primePrint(i);
    }
    return 0;
}