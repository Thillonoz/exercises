#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0xC599
#define MSG_WIDTH 14
#define BUFFER 2

int main()
{
    uint8_t message[MSG_WIDTH] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0}; //'A', 'B'   'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!',

    printf("Original Hex: 0x%X\n Dec:%d\n", message, message);

    uint16_t sum = 0;
    for (int i = 0; i < MSG_WIDTH; i++)
    {

        sum += message[i];
        printf("0x%X\n", sum);
    }
    printf("Sum Hex: 0x%X\n Dec:%d\n", sum, sum);
    uint16_t mod = *message % POLYNOMIAL;
    uint16_t minus = POLYNOMIAL - mod;
    uint16_t plus = minus + *message;
    uint16_t result = plus % POLYNOMIAL;
    printf("Mod: %X\n Mod:%d\n", mod, mod);
    printf("Minus: %X\n Minus:%d\n", minus, minus);
    printf("Plus: %X\n Plus:%d\n", plus, plus);
    printf("result: %X\n result:%d\n", result, result);
    if (result == 0)
    {
        printf("Message intact\n");
    }
    else
    {
        printf("Message not intact\n");
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            message[i] >> 1;
        }
    }

    return 0;
}