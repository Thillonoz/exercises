/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 21

int main()
{
    char array[MAX_LENGTH] = "ABCDCBA";
    int stringLength = strlen(array);
    int arrayCheck = 0;
    int i = 0;
    int l = stringLength - 1;
    while (i <= (stringLength / 2))
    {
        if (array[i] == array[l])
        {
            arrayCheck++;
            i++;
            l--;
            if (arrayCheck == (stringLength / 2))
            {
                printf("It's palindrome\n");
            }
        }
        else
        {
            printf("It's not a palindrome\n");
            break;
        }
    }
    return 0;
}