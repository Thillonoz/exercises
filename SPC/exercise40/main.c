#include "list.h"
#include <stdio.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main(void)
{
    int data[6] = {2, 4, 8, 16, 32, 64};

    list_t *mylist = list_create(mylist);

    assert(list_insert(mylist, 10));
    assert(list_insert(mylist, 20));
    assert(list_insert(mylist, 30));
    assert(list_insert(mylist, 40));
    list_print(mylist);

    assert(list_remove(mylist, 30));
    assert(3 == list_available(mylist));
    list_print(mylist);

    assert(list_change_data(mylist, 2, 50));
    list_print(mylist);

    assert(list_remove(mylist, 10));
    assert(2 == list_available(mylist));
    list_print(mylist);

    assert(list_search(mylist, 50));
    printf("");

    list_destroy(mylist);

    return 0;
}
