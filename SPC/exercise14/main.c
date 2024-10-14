#include <stdio.h>
#include <math.h>

int main()
{
    int num = 54;
    int primeCheck = 0;
    int square = sqrt(num);
    if (num <= 1)
        primeCheck = 0;
    if (num == 2)
        primeCheck = 1;
    if (num % 2 == 0)
        primeCheck = 0;
    for (int i = 3; i <= square; i += 2)
    {
        if (num % i == 0)
        {
            primeCheck = 0;
        }
        else
            primeCheck = 1;
    }

    printf("Given number %d %s a prime number.\n", num, primeCheck == 1 ? "is" : "is not");

    return 0;
}