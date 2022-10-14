#include "sloppy_tests.h"
#include "linked_list.h"
#include <stdio.h>

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
    LinkedList* linked_list = get_new_linked_list();
    insert_after_tail(linked_list, 1);
    insert_after_tail(linked_list, 2);
    insert_after_tail(linked_list, 3);
    insert_after_tail(linked_list, 4);
    printf("Before deleting the head:-\n");
    print_linked_list(linked_list);
    delete_head(linked_list);
    printf("After deleting the head:-\n");
    print_linked_list(linked_list);
}
