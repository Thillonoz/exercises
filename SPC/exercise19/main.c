/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char arr[50];

    printf("Input text: \n");
    fgets(arr, 50, stdin);
    int inputLength = strlen(arr);
    printf("\nOutput: \n");
    for (int i = 0; i < inputLength - 1; i++)
    {
        if (isspace(arr[i]) && isspace(arr[i + 1]))
        {
            while (isspace(arr[i + 1]))
            {
                i++;
                continue;
            }
            printf("\n");
            continue;
        }
        else if (isspace(arr[i]) && !isspace(arr[i - 1]))
        {
            printf("\n");
            continue;
        }
        printf("%c", arr[i]);
    }
    printf("\n");

    return 0;
}