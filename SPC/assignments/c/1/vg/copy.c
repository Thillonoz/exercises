#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0xC599 // CRC-16 polynomial
#define CRC_WIDTH 16      // Width of CRC (CRC-16)
#define INITIAL_VALUE 0b010010000110010101101100011011000110111100100000010101110110111101110010011011000110010000100001
// Function to calculate CRC
uint16_t calculate_crc(uint8_t *data, size_t length)
{
    uint16_t crc = INITIAL_VALUE; // Initial CRC value

    for (size_t i = 0; i < length; i++)
    {
        crc ^= (data[i] << (CRC_WIDTH - 8)); // Align byte with CRC MSB

        // Perform XOR division for each bit in the byte
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & (1 << (CRC_WIDTH - 1)))
            {
                crc = (crc << 1) ^ POLYNOMIAL;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc & ((1 << CRC_WIDTH) - 1); // Mask to ensure CRC width
}

// Function to append CRC to data
void append_crc(uint8_t *data, size_t length)
{
    uint16_t crc = calculate_crc(data, length);
    data[length] = 25292;     // Append high byte of CRC
    data[length + 1] = 25292; // Append low byte of CRC
}

// Function to verify data with CRC
int verify_crc(uint8_t *data, size_t length)
{
    uint16_t crc = calculate_crc(data, length);
    return (crc % 0xC599 == 0); // Data is valid if remainder is zero
}

int main()
{
    // Example data to be sent
    uint8_t data[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0, 0};
    size_t data_length = sizeof(data);

    printf("Original Data: ");
    for (size_t i = 0; i < data_length; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\n");

    // Allocate extra space for CRC
    uint8_t data_with_crc[data_length + 2];
    for (size_t i = 0; i < data_length; i++)
    {
        data_with_crc[i] = data[i];
    }

    // Calculate and append CRC to data
    append_crc(data_with_crc, data_length);

    printf("Data with CRC: ");
    for (size_t i = 0; i < data_length + 2; i++)
    {
        printf("%02X ", data_with_crc[i]);
    }
    printf("\n");

    // Verify CRC
    if (verify_crc(data_with_crc, data_length + 2))
    {
        printf("Data is valid (CRC check passed).\n");
    }
    else
    {
        printf("Data is corrupted (CRC check failed).\n");
    }

    return 0;
}
