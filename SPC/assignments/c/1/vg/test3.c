#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define POLYNOMIAL 0xC599                // CRC-15 polynomial
#define CRC_WIDTH 15                     // Width of the CRC
#define CRC_MASK ((1U << CRC_WIDTH) - 1) // Mask for 15-bit CRC

// Function to calculate CRC-15
uint16_t calculate_crc(const uint8_t *message, size_t length)
{
    uint16_t crc = 0; // Initialize CRC to 0
    uint16_t checking = POLYNOMIAL;

    for (size_t i = 0; i < length; i++)
    {
        uint8_t byte = message[i];

        for (int bit = 0; bit < 8; bit++)
        {
            //  bool bit_in = byte & 1;                       // Extract LSB of the current byte
            // bool bit_out = crc & (1U << 16); // Extract MSB of the CRC
            crc = byte ^ checking; // Apply polynomial if input bit and output bit differ
            byte >>= 1;

            // if (bit_in ^ bit_out)
            // {

            // }

            //checking >>= 1;

            // byte >>= 1; // Shift byte right by 1 to process the next bit
        }
    }

    return crc & 0x7FF;
}

// Function to verify a message with its checksum
bool verify_crc(const uint8_t *message, size_t length, uint16_t checksum)
{
    // Append the checksum to the message and calculate CRC
    uint16_t calculated_crc = calculate_crc(message, length);
    return calculated_crc == checksum;
}

int main()
{
    // Example message
    uint8_t message[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0};
    size_t length = sizeof(message) / sizeof(message[0]);

    // Calculate checksum
    uint16_t checksum = calculate_crc(message, length);
    printf("CRC-15 Checksum: 0x%X\n", checksum);

    // Verify the message with the checksum
    if (verify_crc(message, length, checksum))
    {
        printf("Message verification succeeded.\n");
    }
    else
    {
        printf("Message verification failed.\n");
    }

    return 0;
}