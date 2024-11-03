#include <stdio.h>
void add(int *aptr);
void say_value(int a);

int main(void)
{
    int a = 5;
    char b = 's';

    int *pa = &a;
    char *pb = &b;

    printf("Original value of variable b: %c\n", *pb);
    printf("Now change this using a character: ");
    scanf("%c", pb);
    printf("Modified value: %c\n", *pb);
    printf("Original value of variable a: %d\n", *pa);
    printf("Now change this using a integer: ");
    scanf("%d", pa);
    printf("Modified value: %d\n", *pa);
    printf("Now lets try to add 5 to that integer\n");
    add(pa);

    void *(funcptr)(int) = say_value;
    return 0;
}

void add(int *aptr)
{
    *aptr += 5;
    printf("%d\n", *aptr);
}

void say_value(int a)
{
    printf("Value of a is %d\n", a);
}