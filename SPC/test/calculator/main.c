#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define MAX_LEN 25

int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int div(int x, int y);
void printing(int result);

int main(void)
{
    int first = 0;
    int second = 0;
    char operator;
    int (*operation)(int, int) = NULL; // Function pointer for the operation
    void (*print)(int) = printing;     // Function pointer for printing

    printf("**Calculator**\n");
    printf("Enter two numbers: \n");

    while (2 != scanf("%d %d", &first, &second))
    {
        printf("Wrong input, try again.\n");
        while (getchar() != '\n')
            ;
    }

    getchar(); // Clear the newline character
    printf("Enter an operator (+, -, *, /): \n");
    scanf("%c", &operator);

    // Set the function pointer based on the operator
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
        printf("Invalid operator.\n");
        return 1;
    }

    // Calculate the result and print it
    if (operation != NULL)
    {
        int result = operation(first, second);
        print(result); // Use the print function pointer
    }

    return 0;
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
    if (y == 0)
    {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return x / y;
}

void printing(int result)
{
    printf("Result: %d\n", result);
}
