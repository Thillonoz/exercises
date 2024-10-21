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

    printf("Input a number 0 - 1000 ");
    scanf("%d", &num);

    while (primeCheck(num) != 1)
    {
        printf("Given number %d is not a prime number. Please try again.\n", num);
        scanf("%d", &num);
        primeCheck(num);
    }
    printf("Congratulations, %d is a prime number!.\n", num);
    return 0;
}