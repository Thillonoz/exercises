#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CRC_POLY 0xC599 // CRC-15 polynomial for CAN
#define CRC_INITIAL_VALUE 0

uint16_t calculateCRC15(const char *data)
{
    uint16_t crc = CRC_INITIAL_VALUE;
    while (*data)
    {
        unsigned char ch = *data++;

        for (int i = 7; i >= 0; i--)
        {
            // Shift in each bit of the character to the CRC
            int bit = (ch >> i) & 1;
            int crc_msb = (crc >> 14) & 1; // CRC MSB (15th bit of 16-bit CRC register)

            crc <<= 1; // Shift CRC left by 1
            if (crc_msb ^ bit)
            {
                crc ^= CRC_POLY; // Apply polynomial if MSB of CRC and bit differ
            }
        }
    }

    crc &= 0x7FFF; // Mask to 15 bits
    return crc;
}

int main()
{
    uint8_t text[14] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0};
    uint16_t crc15 = calculateCRC15(text);
    printf("CRC-15 of \"%s\": 0x%04X\n", text, crc15);
    return 0;
}
