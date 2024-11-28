#include "queue.h"
#include <assert.h>

int main(void)
{
    int array[5] = {10, 20, 30, 40, 50};

    int size = sizeof(array) / sizeof(array[0]);
    assert(isEmpty());
    printf("The queue is empty!\n");
    assert(enqueue(array[0]));
    printf("Testing enqueue... passed!\n");
    queue_print();

    assert(enqueue(array[1]));
    printf("Testing enqueue... passed!\n");
    queue_print();

    assert(enqueue(array[2]));
    printf("Testing enqueue... passed!\n");
    queue_print();

    assert(!isEmpty());
    printf("The queue is not empty!\n");

    assert(!isFull());
    printf("The queue is not full\n");

    assert(enqueue(array[3]));
    printf("Testing enqueue... passed!\n");
    queue_print();
    assert(enqueue(array[4]));
    printf("Testing enqueue... passed!\n");
    queue_print();

    assert(isFull());
    printf("The queue is full\n");

    printf("Dequeue!\n");
    dequeue();
    queue_print();
    assert(!isFull());
    printf("The queue is not full\n");

    assert(enqueue(55));
    printf("Testing enqueue... passed!\n");
    queue_print();

    assert(isFull());
    printf("The queue is full\n");

    return 0;
}