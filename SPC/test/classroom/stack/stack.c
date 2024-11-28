#include "stack.h"

#define STACK_SIZE 5

int stack[STACK_SIZE] = {0};
int available = 0;
int head = 0;
int tail = 0;

bool push(int data)
{
    bool status = false;
    if (!isFull())
    {
        if (*stack == 0)
        {
            stack[head] = data;
        }

        stack[head] = data;

        available++;
        head++;
        status = true;
    }

    return status;
}

bool pop(void)
{
    bool status = false;

    available--;
    head--;
    status = true;

    return status;
}

void stack_print(void)
{
    for (size_t i = tail; i < head; i++)
    {
        (void)printf("%d\t", stack[i]);
    }
    (void)printf("\n");
}

bool isEmpty(void)
{
    return available == 0;
}

bool isFull(void)
{
    printf("Available %d\n", available);
    return available == STACK_SIZE;
}