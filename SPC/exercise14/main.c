#include <stdio.h>
#include <math.h>

int primeCheck(int num)
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
    int num = 0;
    while (num < 1 || num > 1000)
    {
        printf("Input a number 0 - 10000 ");
        scanf("%d", &num);
    }

    if (primeCheck(num) == 1)
    {
        printf("Given number %d is a prime number.\n", num);
    }
    else
    {
        printf("Given number %d is not a prime number.\n", num);
    }
    return 0;
}