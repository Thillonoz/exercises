#include "list.h"
#include <stdio.h>
#include <assert.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static void insert_into_list(int *array, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        assert(list_insert(array[i]));
        assert(i + 1 == list_available());
    }
}

void test_list_insert(void)
{
    int data[4] = {10, 2, 8, 20};
    insert_into_list(data, ARRAY_SIZE(data));

    // Check if the data is sorted
    int value = 0;
    assert(list_get_data(1, &value));
    assert(10 == value);

    assert(list_get_data(2, &value));
    assert(2 == value);

    assert(list_get_data(3, &value));
    assert(8 == value);

    assert(list_get_data(4, &value));
    assert(20 == value);

    // Test for invalid positions
    assert(!list_get_data(0, &value));
    assert(!list_get_data(10, &value));

    list_delete();
    assert(0 == list_available());
}

void test_list_find(void)
{
    assert(!list_find(40)); // Test for a non-existing value (when the list is empty)

    int data[3] = {30, 5, 10};
    insert_into_list(data, ARRAY_SIZE(data));

    assert(2 == list_find(5));
    assert(3 == list_find(10));

    assert(0 == list_find(40)); // Test for a non-existing value

    list_delete();
    assert(0 == list_available());
}

void test_list_remove(void)
{
    assert(!list_remove(33)); // Test for an invalid position (when the list is empty)

    int data[4] = {10, 2, -8, 20};
    insert_into_list(data, ARRAY_SIZE(data));

    assert(!list_remove(0)); // // Test for an invalid position

    assert(list_remove(3));

    assert(3 == list_available());
    assert(0 == list_find(-8));

    assert(list_insert(-8));
    assert(4 == list_available());
    assert(4 == list_find(-8));

    list_delete();
    assert(0 == list_available());
}

void test_list_update(void)
{
    assert(!list_update(33, 1)); // Test for an invalid position (when the list is empty)

    int data[4] = {10, 2, -8, 20};
    insert_into_list(data, ARRAY_SIZE(data));

    assert(list_update(3, 8));

    assert(!list_update(5, 50)); // Test for an invalid position.

    // Check for the data
    int value = 0;
    assert(list_get_data(1, &value));
    assert(10 == value);

    assert(list_get_data(2, &value));
    assert(2 == value);

    assert(list_get_data(3, &value));
    assert(8 == value);

    assert(list_get_data(4, &value));
    assert(20 == value);

    list_delete();
    assert(0 == list_available());
}

int main(void)
{
    test_list_insert();
    (void)printf("\nTesting insert... Passed\n");

    test_list_find();
    (void)printf("Testing find... Passed\n");

    test_list_remove();
    (void)printf("Testing remove... Passed\n");

    test_list_update();
    (void)printf("Testing update... Passed\n");

    (void)printf("-----------------------------\n");
    (void)printf("All tests Passed!\n\n");

    return 0;
}
