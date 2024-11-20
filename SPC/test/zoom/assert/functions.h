#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

static void sortArray(uint8_t *arr, uint8_t length);
static bool is_sorted(uint8_t *arr, uint8_t length);
void testSort(uint8_t *arr, uint8_t length);

#endif