#include "functions.h"

// Function to sort an array of type uint8_t
static void sortArray(uint8_t *arr, uint8_t length)
{
    for (uint8_t i = 0; i < length - 1; i++)
    {
        // Last i elements are already sorted, so skip them
        for (uint8_t j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                uint8_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to check if the array is sorted
static bool is_sorted(uint8_t *arr, uint8_t length)
{
    for (uint8_t i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
            break;
        }
    }
    return true;
}

// Function to test if the sorting worked
void testSort(uint8_t *arr, uint8_t length)
{
    sortArray(arr, length);
    (void)printf("The sorted array:\n");
    for (int i = 0; i < length; i++)
    {
        (void)printf("%hhu\t", arr[i]);
    }
    (void)printf("\n");

    assert(is_sorted(arr, length));
    (void)printf("The sorting has passed!\n");
}
