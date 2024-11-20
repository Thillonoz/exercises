
#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define STRING_MAX_LEN 64

// Function to print a string
int printString(const char *string, uint8_t length);

/*
Function to sort alphabetically and
keep uppercase and lowercase together
*/
int compareCharacters(char a, char b);

// Function to sort a given string
int strSort(char *str, uint8_t length);
/*
// Function to find the least common multiple
for 2 given unsigned integers
*/
uint8_t lcm(uint8_t a, uint8_t b);
/*
Function to find the greatest common divisor
for 2 given unsigned integers
*/
uint8_t gcd(uint8_t a, uint8_t b);

#endif