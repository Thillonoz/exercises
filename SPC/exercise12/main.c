#include <stdio.h>
int main()
{
    int sum = 0;
    int input = 0;
    printf("Enter number: ");
    scanf("%d", &input);

    for (int i = 0; i < input; i += 2)
    {
        sum += i;
    }

    printf("%d\n", sum);
    return 0;
}