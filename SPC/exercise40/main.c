#include "linkedlist.h"
#include <assert.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void)
{
    int data[6] = {2, 4, 8, 16, 32, 64};

    for (size_t i = 0; i < ARRAY_SIZE(data); i++)
    {
        newNode(data[i]);
    }
    assert(changeValue(3, 6));

    return 0;
}