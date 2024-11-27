#include "list.h"

int main(void)
{
    int data[4] = {10, 20, 30, 40};
    list_t *mylist = list_create(mylist);

    assert(list_insert(mylist, data[0]));
    assert(list_insert(mylist, data[1]));
    assert(list_insert(mylist, data[2]));
    assert(list_insert(mylist, data[3]));
    (void)printf("Original list:\t\t");
    list_print(mylist);

    assert(list_remove(mylist, data[2]));
    assert(3 == list_available(mylist));
    (void)printf("Deleted an element:\t");
    list_print(mylist);

    assert(list_remove(mylist, data[3]));
    assert(2 == list_available(mylist));
    (void)printf("Deleted an element:\t");
    list_print(mylist);

    assert(list_change_data(mylist, 2, 50));
    (void)printf("Change a element:\t");
    list_print(mylist);

    assert(list_remove(mylist, 50));
    assert(1 == list_available(mylist));
    (void)printf("Delete last element:\t");
    list_print(mylist);

    assert(list_search(mylist, data[0]));
    printf("Found %d in the list: %d\n", data[0], data[0]);

    list_destroy(mylist);

    return 0;
}