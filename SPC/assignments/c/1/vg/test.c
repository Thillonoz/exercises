#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0xC599 // CRC polynomial (0xC599)

// Function to calculate CRC for a given message (byte array) and polynomial
uint16_t calculate_crc(const uint8_t *message, size_t length)
{
    uint16_t crc = 0xFFFF; // Initial value for CRC

    // Process each byte of the message
    for (size_t i = 0; i < length; i++)
    {
        crc ^= (uint16_t)message[i] << 8;

        for (int j = 0; j < 8; j++)
        { // Process each bit
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ POLYNOMIAL;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

// Function to verify CRC by adding it to the message and checking the result
int verify_crc(const uint8_t *message, size_t length, uint16_t received_crc)
{
    uint16_t calculated_crc = calculate_crc(message, length);

    return calculated_crc == received_crc;
}

int main()
{
    // Message to encode (corresponding to "Hello World!")
    uint8_t message[] = {
        0x48, 0x65, 0x6C, 0x6C, 0x6F, // "Hello"
        0x20,                         // Space
        0x57, 0x6F, 0x72, 0x6C, 0x64, // "World"
        0x21, 0, 0                    // "!"
    };

    size_t length = sizeof(message) / sizeof(message[0]);

    // Calculate CRC for the message
    uint16_t crc = calculate_crc(message, length);
    printf("Calculated CRC: 0x%X\n", crc);

    // Simulate transmission and verify the message with the CRC
    if (verify_crc(message, length, crc))
    {
        printf("CRC validation passed.\n");
    }
    else
    {
        printf("CRC validation failed.\n");
    }

    return 0;
}
