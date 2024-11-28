#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool push(int data);

void stack_print(void);

bool pop(void);

bool isEmpty(void);

bool isFull(void);

#endif