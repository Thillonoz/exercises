#include "list.h"
#include <stdio.h>

#define N 3

int data[4] = {10, 20, 30, 40};
int arrSize = sizeof(data) / sizeof(data[0]);

void test_list_insert(list_t *lst, int *array);
void test_list_print(list_t *lst);

int main(void)
{

    int numberofElements = 0;

    list_t *mylist = list_create(mylist);

    test_list_insert(mylist, data);
    (void)printf("Testing if inserting the data to the list is successful... passed!\n");

    test_list_print(mylist);
    (void)printf("\nTesting if printing the list works... passed!\n\n");

    assert(arrSize == list_available(mylist));
    (void)printf("Checking if the list is filled... passed!\n\n");

    numberofElements = list_available(mylist);
    (void)printf("Checking number of elements in the list... %d!\n\n", numberofElements);

    assert(list_get_data(mylist, N));
    (void)printf("Found %d in the list: \t%d\n\n", data[N], data[N]);

    assert(list_remove(mylist, data[2]));
    assert(3 == list_available(mylist));

    (void)printf("Deleted an element:\t");
    test_list_print(mylist);

    list_new_insert(mylist, data[2]);
    (void)printf("Added element back:\t");
    test_list_print(mylist);

    assert(list_remove(mylist, data[3]));
    assert(2 == list_available(mylist));

    (void)printf("Deleted an element:\t");
    test_list_print(mylist);

    assert(list_change_data(mylist, 2, 50));
    (void)printf("Change a element:\t");
    test_list_print(mylist);

    assert(list_remove(mylist, 50));
    assert(1 == list_available(mylist));
    (void)printf("Delete last element:\t");
    test_list_print(mylist);

    assert(list_search(mylist, data[0]));
    (void)printf("\nFound %d in the list: \t%d\n\n", data[0], data[0]);

    list_destroy(mylist);
    assert(0 == list_available(mylist));
    (void)printf("Testing if the list is destroyed... passed!\n");

    return 0;
}

void test_list_insert(list_t *lst, int *array)
{
    for (size_t i = 0; i < arrSize; i++)
    {
        assert(list_insert(lst, array[i]));
    }
}

void test_list_print(list_t *lst)
{
    (void)printf("List:\t\t");
    list_print(lst);
}