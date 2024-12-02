#include <stdint.h>
#include <stdio.h>

// Function to calculate CRC
uint16_t calculate_crc(const uint8_t *message, size_t length, uint16_t polynomial, uint8_t degree)
{
    uint16_t crc = 0; // Initial CRC value
    for (size_t i = 0; i < length; i++)
    {
        // Process each byte from LSB to MSB
        for (uint8_t bit = 0; bit < 8; bit++)
        {
            // Bring the next bit into CRC
            uint8_t bit_in = (message[i] >> bit) & 1;
            crc ^= (bit_in << (degree - 1));
            // Perform polynomial division
            if (crc & (1 << (degree - 1)))
            {
                crc = (crc << 1) ^ polynomial;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc & ((1 << degree) - 1); // Mask to CRC length
}

// Function to verify the message
int verify_crc(const uint8_t *message, size_t length, uint16_t polynomial, uint8_t degree, uint16_t checksum)
{
    uint16_t crc = calculate_crc(message, length, polynomial, degree);
    // Append the checksum and perform the final CRC calculation
    for (int bit = degree - 1; bit >= 0; bit--)
    {
        uint8_t bit_in = (checksum >> bit) & 1;
        crc ^= (bit_in << (degree - 1));
        if (crc & (1 << (degree - 1)))
        {
            crc = (crc << 1) ^ polynomial;
        }
        else
        {
            crc <<= 1;
        }
    }
    return (crc & ((1 << degree) - 1)) == 0; // Data is healthy if remainder is 0
}

int main()
{
    uint8_t message[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0}; // Example message
    size_t length = sizeof(message) / sizeof(message[0]);
    uint16_t polynomial = 0xC599; // CRC-15 polynomial
    uint8_t degree = 15;          // Degree of the polynomial

    // Calculate the checksum
    uint16_t checksum = calculate_crc(message, length, polynomial, degree);
    printf("Calculated Checksum: 0x%X\n", checksum);

    // Append the checksum to the message (virtually)
    int is_healthy = verify_crc(message, length, polynomial, degree, checksum);
    if (is_healthy)
    {
        printf("Data is healthy.\n");
    }
    else
    {
        printf("Data is corrupted.\n");
    }

    return 0;
}
