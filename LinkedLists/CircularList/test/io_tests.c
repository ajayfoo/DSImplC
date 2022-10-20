//
// Created by ajay on 10/16/22.
//
#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>

CircularList* get_dummy_circular_list(void)
{
    CircularList* new_circular_list = get_new_circular_list();
    insert_after_tail(new_circular_list, 1);
    insert_after_tail(new_circular_list, 2);
    insert_after_tail(new_circular_list, 3);
    insert_after_tail(new_circular_list, 4);
    insert_after_tail(new_circular_list, 5);
    return new_circular_list;
}

void test_print_circular_list(void)
{
    CircularList* new_circular_list = get_dummy_circular_list();
    insert_at(new_circular_list, 1, 11);
    insert_at(new_circular_list, 1, 22);
    printf("Before deleting the head thrice: ");
    print_circular_list(new_circular_list);
    delete_head(new_circular_list);
    delete_head(new_circular_list);
    delete_head(new_circular_list);
    delete_tail(new_circular_list);
    printf("After deleting the head thrice, tail once: ");
    print_circular_list(new_circular_list);
    delete_at(new_circular_list, 1);
    printf("After deleting the element at [1]: ");
    print_circular_list(new_circular_list);
    clear_circular_list(new_circular_list);
}

int main(void)
{
    test_print_circular_list();
    return 0;
}
