#include <stdio.h>
#include <stdint.h>

#define POLY 0xC599          // CAN CRC-15 polynomial
#define CRC_WIDTH 15         // Number of bits in CRC-15
#define CRC_INIT 0x0000      // Initial CRC value for CAN CRC-15
#define CRC_FINAL_XOR 0x0000 // Final XOR value if required

uint16_t crc15(uint8_t *data, size_t length)
{
    uint16_t crc = CRC_INIT; // Initialize CRC with the specified initial value

    for (size_t i = 0; i < length; i++)
    {
        crc ^= (data[i] << (CRC_WIDTH - 8)); // Align the byte with CRC's high bit

        for (int bit = 0; bit < 8; bit++)
        {
            if (crc & (1 << (CRC_WIDTH - 1)))
            {                            // If the leftmost bit is set
                crc = (crc << 1) ^ POLY; // Shift left and XOR with polynomial
            }
            else
            {
                crc <<= 1; // Just shift left
            }
        }
    }

    crc &= 0x7FFF;              // Mask to 15 bits (CRC-15)
    return crc ^ CRC_FINAL_XOR; // Apply the final XOR if required
}

int main()
{
    uint8_t data[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'}; // Example data
    size_t length = sizeof(data) / sizeof(data[0]);

    uint16_t crc = crc15(data, length);
    printf("CRC-15 checksum: 0x%04X\n", crc);

    return 0;
}
