#include "list.h"
#include <assert.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void test_list_create_list(void);

int main(void)
{
    int data[6] = {2, 4, 8, 16, 32, 64};

    assert(list_insert(10));
    assert(list_insert(20));
    assert(list_insert(30));
    assert(list_insert(40));

    list_print();
    assert(list_remove(30));
    assert(3 == list_available());
    list_print();

    assert(list_remove(10));
    assert(2 == list_available());
    list_print();

    list_destroy();

    return 0;
}
