/**
 * @file main.c
 * @author Emil Ivarsson (emilivarsson92@gmail.com)
 * @brief A program to calculate the CRC of given data and check and validate the checksum
 * @version 0.1
 * @date 2024-11-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define POLYNOMIAL 0xC599
#define N 14
#define BIT_SIZE 8
#define BIT_SHIFT 1

uint16_t compute_crc(const uint8_t *message, size_t length);
bool verify_crc(const uint8_t *message, size_t length, uint16_t received_crc);

int main(void)
{
    uint8_t message[N] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0}; // Example message
    size_t length = sizeof(message) / sizeof(message[0]);

    // Compute CRC-15 for the message
    uint16_t crc = compute_crc(message, length);
    printf("CRC-15 checksum: 0x%X\n", crc);
    // Verify the CRC
    bool is_valid = verify_crc(message, length, crc);
    printf("CRC verification: %s\n", is_valid ? "Passed" : "Failed");

    return 0;
}

// Function to compute CRC-15 checksum
uint16_t compute_crc(const uint8_t *message, size_t length)
{
    uint16_t crc = 0x0000; // Initial CRC value (0 or all 1s is common)

    for (uint8_t i = 0; i < length; i++)
    {
        uint8_t byte = *(message + i);
        uint8_t bit = byte & 1; // Extract the LSB

        // Process each bit in the byte, from LSB to MSB
        for (uint8_t j = 0; j < BIT_SIZE; j++)
        {
            bit >>= j; // Shift to the next bit in the byte

            // Update the CRC by shifting left by 1 and XORing with the polynomial
            if ((crc & (1 << N)) ^ (bit << N))
            {
                crc = (crc << BIT_SHIFT) ^ POLYNOMIAL;
            }
            else
            {
                crc <<= BIT_SHIFT;
            }
        }
    }
    // Mask to ensure CRC is within the 15-bit range
    crc &= 0xFFF;

    // Mask to flip bits
    crc = crc ^ 0x600;

    return crc;
}

// Function to verify CRC on a message with appended checksum
bool verify_crc(const uint8_t *message, size_t length, uint16_t received_crc)
{
    uint16_t crc = compute_crc(message, length);
    // Append the checksum and perform the final CRC calculation
    for (int bit = N; bit >= 0; bit--)
    {
        uint8_t bit_in = (received_crc >> bit) & 1;
        crc ^= (bit_in << N);
        if (crc & (1 << N))
        {
            crc = (crc << 1) ^ POLYNOMIAL;
        }
        else
        {
            crc <<= 1;
        }
    }
    return (crc & (1 << N)) == 0; // Data is healthy if remainder is 0
}