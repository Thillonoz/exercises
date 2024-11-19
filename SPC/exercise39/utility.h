
#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRING_MAX_LEN 64 // Shall be an integer in the range of 8 and 64

void strSort(const char *string);

bool strComp(const char *string, const char *string1);

#endif