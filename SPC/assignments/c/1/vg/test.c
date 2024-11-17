/**
 * @file test.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief This program does CRC-15 checking to a message
 * @version 0.1
 * @date 2024-11-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0xC599
#define CRC_WIDTH 15
#define N 14
#define BIT_SIZE 8
#define BIT_SHIFT 1
#define CRC_INIT 0x0000 // Initial CRC value

uint16_t crc15(uint8_t *data, size_t length)
{
    uint16_t crc = CRC_INIT; // Initialize CRC with the specified initial value
    uint16_t sum = 0;

    for (uint8_t i = 0; i < length; i++)
    {
        crc ^= (data[i] << (CRC_WIDTH - BIT_SIZE)); // Align the byte with CRC's high bit

        for (uint8_t j = 0; j < BIT_SIZE; j++)
        {
            if (crc & (BIT_SHIFT << (CRC_WIDTH - 1))) // If the leftmost bit is set
            {
                sum += (crc << BIT_SHIFT) ^ POLYNOMIAL; // Shift left and XOR with polynomial
            }
            else
            {
                crc <<= BIT_SHIFT; // Just shift left
            }
        }
    }
    return sum;
}

int main(void)
{
    uint8_t data[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'}; // Example data
    size_t length = sizeof(data) / sizeof(data[0]);

    uint16_t sum = crc15(data, length);
    (void)printf("CRC-15 checksum: 0x%X\n", sum);

    return 0;
}
