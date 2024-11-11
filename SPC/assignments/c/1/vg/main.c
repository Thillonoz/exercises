#include <stdint.h>
#include <stdio.h>

#define POLYNOMIAL 0xC599 // CRC-15 polynomial
#define CRC_WIDTH 15      // Width of the CRC

// Function to compute CRC-15 checksum
uint16_t compute_crc(const uint8_t *message, size_t length)
{
    uint16_t crc = 0; // Initial CRC value (0 or all 1s is common)

    for (size_t i = 0; i < length; i++)
    {
        uint8_t byte = message[i];

        // Process each bit in the byte, from LSB to MSB
        for (int j = 0; j < 8; j++)
        {
            uint8_t bit = byte & 1; // Extract the LSB
            byte >>= 1;             // Shift to the next bit in the byte

            // Update the CRC by shifting left by 1 and XORing with the polynomial
            if ((crc & (1 << (CRC_WIDTH - 1))) ^ (bit << (CRC_WIDTH - 1)))
            {
                crc = (crc << 1) ^ POLYNOMIAL;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    // Mask to ensure CRC is within the 15-bit range
    return crc & 0x7FFF;
}

// Function to verify CRC on a message with appended checksum
int verify_crc(const uint8_t *message, size_t length, uint16_t received_crc)
{
    uint16_t computed_crc = compute_crc(message, length);
    return (computed_crc == received_crc);
}

int main()
{
    uint8_t message[] = {0x32, 0x45, 0x67}; // Example message
    size_t length = sizeof(message) / sizeof(message[0]);

    // Compute CRC-15 for the message
    uint16_t crc = compute_crc(message, length);
    printf("CRC-15 checksum: 0x%X\n", crc);

    // Verify the CRC
    int is_valid = verify_crc(message, length, crc);
    printf("CRC verification: %s\n", is_valid ? "Passed" : "Failed");

    return 0;
}
