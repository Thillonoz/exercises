#include <stdio.h>
#include <stdint.h>

#define POLY 0x6599          // Correct CRC-15 polynomial (15 bits)
#define CRC_WIDTH 15         // Number of bits in CRC-15
#define CRC_INIT 0x0000      // Initial CRC value
#define CRC_FINAL_XOR 0x0000 // Final XOR value (usually 0x0000 for CRC-15)

uint16_t crc15_checksum(uint8_t *data, size_t length)
{
    uint16_t crc = CRC_INIT; // Initialize CRC value

    // Process each byte of data
    for (size_t i = 0; i < length; i++)
    {
        uint8_t byte = data[i];

        // Process each bit of the byte (LSB to MSB)
        for (int bit = 0; bit < 8; bit++)
        {
            // Shift CRC to the right by 1 to make room for the next bit
            uint8_t bit_value = byte & 1; // Extract the LSB of the byte
            byte >>= 1;                   // Shift byte to process the next bit

            // Shift CRC to the right by 1
            crc >>= 1;

            // If the LSB of the CRC and the current bit from the message differ
            if (bit_value ^ (crc & 1))
            {
                crc ^= POLY; // XOR with the polynomial
            }
        }
    }

    crc &= 0x7FF;               // Mask to 15 bits (CRC-15)
    return crc ^ CRC_FINAL_XOR; // Apply final XOR (if any)
}

int main()
{
    // Message with two appended zeros (as per assignment)
    uint8_t message[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0x00, 0x00};
    size_t length = sizeof(message) / sizeof(message[0]);

    // Calculate CRC checksum
    uint16_t checksum = crc15_checksum(message, length);
    printf("CRC-15 checksum: 0x%03X\n", checksum >> 1);

    return 0;
}
