/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
void add(int *aptr);
void say_value(int a);

int main(void)
{
    int a = 5;
    char b = 's';

    int *pa = &a;
    char *pb = &b;
    (void)printf("Original value of variable b: %c\n", *pb);
    (void)printf("Now change this using a character: ");
    scanf("%c", pb);
    (void)printf("Modified value: %c\n", *pb);
    (void)printf("Original value of variable a: %d\n", *pa);
    (void)printf("Now change this using a integer: ");
    scanf("%d", pa);
    (void)printf("Modified value: %d\n", *pa);
    (void)printf("Now lets try to add 5 to that integer\n");
    add(pa);
    void (*funcptr)(int);
    funcptr = say_value;
    funcptr(32);

    return 0;
}

void add(int *aptr)
{
    *aptr += 5;
    (void)printf("%d\n", *aptr);
}

void say_value(int a)
{
    (void)printf("Value of a is %d\n", a);
}