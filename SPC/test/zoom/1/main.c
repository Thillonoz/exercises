#include <stdio.h>

#define SIZE 3

void display_matrix(int matrix[SIZE][SIZE]);
void multiply_constant(int matrix[SIZE][SIZE], int constant);
void add_constant(int matrix[SIZE][SIZE], int constant);
void transpose_matrix(int matrix[SIZE][SIZE]);
void (*operation[2])(int (*)[SIZE], int) = {multiply_constant, add_constant};

int main(void)
{
    // Declaring an array and constant
    int array[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    const int constant = 5;
    int userChoice = 0;
    printf("This is the original matrix\n");
    display_matrix(array);
    printf("Choose your operation (1) Multiply or (2) Add\n");
    if (1 == scanf("%d", &userChoice))
    {
        if (userChoice == 1 || userChoice == 2)
        {
            operation[userChoice - 1](array, constant);
            display_matrix(array);
        }
    }

    return 0;
}

void display_matrix(int matrix[SIZE][SIZE])
{
    // Using nested for loops to print each element of the array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            (void)printf("%d ", matrix[i][j]);
        }
        (void)printf("\n");
    }
    // Printing a new line for clarity in the output
    (void)printf("\n");
}

void multiply_constant(int matrix[SIZE][SIZE], int constant)
{
    //
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] *= constant;
        }
    }
}

void add_constant(int matrix[SIZE][SIZE], int constant)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] += constant;
        }
    }
}

void transpose_matrix(int matrix[SIZE][SIZE])
{
    int temp = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
