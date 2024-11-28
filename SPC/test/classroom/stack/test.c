#include "stack.h"
#include <assert.h>

int main(void)
{
    int array[5] = {10, 20, 30, 40, 50};

    int size = sizeof(array) / sizeof(array[0]);
    assert(isEmpty());
    printf("The stack is empty!\n");
    assert(push(array[0]));
    printf("Testing push... passed!\n");
    stack_print();

    assert(push(array[1]));
    printf("Testing push... passed!\n");
    stack_print();

    assert(push(array[2]));
    printf("Testing push... passed!\n");
    stack_print();

    assert(!isEmpty());
    printf("The stack is not empty!\n");

    assert(!isFull());
    printf("The stack is not full\n");

    assert(push(array[3]));
    printf("Testing push... passed!\n");
    stack_print();
    assert(push(array[4]));
    printf("Testing push... passed!\n");
    stack_print();

    assert(isFull());
    printf("The stack is full\n");

    printf("pop!\n");
    pop();
    stack_print();
    assert(!isFull());
    printf("The stack is not full\n");

    assert(push(55));
    printf("Testing push... passed!\n");
    stack_print();

    assert(isFull());
    printf("The stack is full\n");

    return 0;
}