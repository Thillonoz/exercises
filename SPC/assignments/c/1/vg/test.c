#include <stdio.h>
#include <stdint.h>

#define CRC 0xC599
#define MESSAGE_WIDTH 15

int main(void)
{

    uint8_t test[MESSAGE_WIDTH] = "";

    scanf("%hhu", &test);

    printf("%x\n", test[0]);

    return 0;
}