#include <stdio.h>
#include <stdint.h>

#define NUM_BITS 8

void binaryConversion(int num);

int main(void)
{
    int num = 0;
    printf("Input a number 0-255: \n");
    scanf("%d", &num);
    while (num < 0 || num > 255)
    {
        printf("Input a number 0-255: \n");
        scanf("%d", &num);
    }
    binaryConversion(num);

    return 0;
}

void binaryConversion(int num)
{
    int binArray[NUM_BITS];
    int mask = 1;
    for (int i = NUM_BITS; i > 0; i--)
    {
        if (num & mask)
        {
            binArray[i] = 1;
        }
        else
        {
            binArray[i] = 0;
        }
        mask = mask << 1;
        
    }
    for (int i = 1; i <= NUM_BITS; i++)
    {
        printf("%d", binArray[i]);
    }
    
    printf("\n");
}