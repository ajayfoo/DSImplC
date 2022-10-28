//
// Created by ajay on 10/16/22.
//
#include "circular_list.h"
#include <stdio.h>

void init_dummy_circular_list(CircularList* circular_list)
{
    init_circular_list(circular_list);
    insert_after_tail(circular_list, 1);
    insert_after_tail(circular_list, 2);
    insert_after_tail(circular_list, 3);
    insert_after_tail(circular_list, 4);
    insert_after_tail(circular_list, 5);
}

void test_print_circular_list(void)
{
    CircularList circular_list;
    init_dummy_circular_list(&circular_list);
    print_circular_list(&circular_list);
    insert_at(&circular_list, 1, 11);
    insert_at(&circular_list, 1, 22);
    printf("Before deleting the head thrice: ");
    print_circular_list(&circular_list);
    delete_head(&circular_list);
    delete_head(&circular_list);
    delete_head(&circular_list);
    delete_tail(&circular_list);
    printf("After deleting the head thrice, tail once: ");
    print_circular_list(&circular_list);
    delete_at(&circular_list, 1);
    printf("After deleting the element at [1]: ");
    print_circular_list(&circular_list);
    clear_circular_list(&circular_list);
}

int main(void)
{
    test_print_circular_list();
    return 0;
}
