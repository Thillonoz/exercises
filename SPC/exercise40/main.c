#include "list.h"
#include <stdio.h>

#define N 3

int data[4] = {10, 20, 30, 40};
int arrSize = sizeof(data) / sizeof(data[0]);

void test_list_insert(list_t *lst, int *array);
void test_list_print(list_t *lst);

int main(void)
{

    int listofElements = 0;

    list_t *mylist = list_create(mylist);

    test_list_insert(mylist, data);
    (void)printf("Testing if inserting the data to the list is successful... passed!\n");

    test_list_print(mylist);
    (void)printf("Testing if printing the list works... passed!\n");

    assert(arrSize == list_available(mylist));
    (void)printf("Checking if the list is filled... passed!\n");
    listofElements = list_available(mylist);
    (void)printf("Checking number of elements in the list... %d!\n", listofElements);

    assert(list_get_data(mylist, N));
    (void)printf("Found %d in the list: \t%d\n", data[N], data[N]);

    assert(list_remove(mylist, data[2]));
    assert(3 == list_available(mylist));

    (void)printf("Deleted an element:\t");
    test_list_print(mylist);
    (void)printf("Testing if printing the list works... passed!\n");

    assert(list_remove(mylist, data[3]));
    assert(2 == list_available(mylist));

    (void)printf("Deleted an element:\t");
    test_list_print(mylist);
    (void)printf("Testing if printing the list works... passed!\n");

    assert(list_change_data(mylist, 2, 50));
    (void)printf("Change a element:\t");
    test_list_print(mylist);
    (void)printf("Testing if printing the list works... passed!\n");

    assert(list_remove(mylist, 50));
    assert(1 == list_available(mylist));
    (void)printf("Delete last element:\t");
    test_list_print(mylist);
    (void)printf("Testing if printing the list works... passed!\n");

    assert(list_search(mylist, data[0]));
    (void)printf("Found %d in the list: \t%d\n", data[0], data[0]);

    list_destroy(mylist);
    assert(0 == list_available(mylist));
    (void)printf("Testing if the list is destroyed... passed!\n");

    return 0;
}

void test_list_insert(list_t *lst, int *array)
{
    assert(list_insert(lst, array[0]));
    assert(list_insert(lst, array[1]));
    assert(list_insert(lst, array[2]));
    assert(list_insert(lst, array[3]));
}

void test_list_print(list_t *lst)
{
    (void)printf("List:\t\t");
    list_print(lst);
}