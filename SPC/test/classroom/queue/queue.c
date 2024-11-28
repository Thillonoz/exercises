#include "queue.h"

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE] = {0};
int available = 0;
int head = 0;
int tail = -1;

bool enqueue(int data)
{

    if (isFull())
    {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return false;
    }
    tail = (tail + 1) % QUEUE_SIZE; // Circular increment
    queue[tail] = data;
    available++;
    return true;

    // bool status = false;
    // if (!isFull())
    // {

    //     queue[head] = data;

    //     available++;
    //     head++;
    //     status = true;
    // }

    // return status;
}

bool dequeue(void)
{

    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return false;
    }
    head = (head + 1) % QUEUE_SIZE; // Circular increment
    available--;
    return true;

    // bool status = false;

    // available--;
    // head = tail;
    // tail++;
    // status = true;

    // return status;
}

void queue_print(void)
{
    for (int i = 0; i < available; i++)
    {
        int index = (head + i) % QUEUE_SIZE;
        printf("%d ", queue[index]);
    }
}

bool isEmpty(void)
{
    return available == 0;
}

bool isFull(void)
{
    printf("Available %d\n", available);
    return available == QUEUE_SIZE;
}