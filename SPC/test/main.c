#include <stdio.h>
#include <ctype.h>

int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int div(int x, int y);
void printing(int sum);

int main(void)
{
    static int first = 0;
    static int second = 0;
    char operator;
    int (*operation)(int, int) = NULL;
    void (*print)(int) = printing;
    (void)printf("**Calculator**\n");
    (void)printf("Enter two numbers: \n");
    while (2 != scanf("%d %d", &first, &second))
    {
        (void)printf("Wrong input, try again.\n");
        while (getchar() != '\n')
            ;
    }
    getchar();
    (void)printf("Enter an operator (+, -, *, /): \n");
    scanf("%c", &operator);
    switch (operator)
    {
    case '+':
        operation = add;
        break;

    case '-':
        operation = sub;
        break;
    case '*':
        operation = mult;
        break;
    case '/':
        operation = div;
        break;
    default:
        (void)printf("Invalid operator.\n");
        break;
    }

    if (operation != NULL)
    {
        int result = operation(first, second);
        print(result);

        return 0;
    }
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mult(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

void printing(int sum)
{
    (void)printf("%d\n", sum);
}