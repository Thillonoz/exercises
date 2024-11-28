#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool enqueue(int data);

void queue_print(void);

bool dequeue(void);

bool isEmpty(void);

bool isFull(void);

#endif