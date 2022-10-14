#include "sloppy_tests.h"
#include "linked_list.h"
#include <stdio.h>

LinkedList* get_dummy_linked_list(void)
{
    LinkedList* linked_list = get_new_linked_list();
    insert_after_tail(linked_list, 1);
    insert_after_tail(linked_list, 2);
    insert_after_tail(linked_list, 3);
    insert_after_tail(linked_list, 4);
    insert_after_tail(linked_list, 4 + 1);
    return linked_list;
}

void test_insert_at_head(void)
{
    LinkedList* linked_list = get_new_linked_list();
    insert_at_head(linked_list, 1);
    insert_at_head(linked_list, 2);
    insert_at_head(linked_list, 3);
    insert_at_head(linked_list, 4);
    print_linked_list(linked_list);
}

void test_delete_head(void)
{
    LinkedList* linked_list = get_dummy_linked_list();
    printf("Before deleting the head:-\n");
    print_linked_list(linked_list);
    delete_head(linked_list);
    printf("After deleting the head:-\n");
    print_linked_list(linked_list);
}

void test_delete_tail(void)
{
    LinkedList* linked_list = get_dummy_linked_list();
    printf("Before deleting the tail:-\n");
    print_linked_list(linked_list);
    printf("After deleting the tail:-\n");
    delete_tail(linked_list);
    print_linked_list(linked_list);
}

void test_delete_at(void)
{
    LinkedList* linked_list = get_dummy_linked_list();
    const size_t index = 2;
    printf("Before deleting the element at index %zu:-\n", index);
    print_linked_list(linked_list);
    delete_at(linked_list, index);
    printf("After deleting the element at index %zu:-\n", index);
    print_linked_list(linked_list);
}
