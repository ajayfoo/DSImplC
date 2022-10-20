//
// Created by ajay on 10/16/22.
//
#include "linked_list.h"

void init_dummy_linked_list(LinkedList* linked_list)
{
    init_linked_list(linked_list);
    insert_after_tail(linked_list,1);
    insert_after_tail(linked_list,2);
    insert_after_tail(linked_list,3);
    insert_after_tail(linked_list,4);
    insert_after_tail(linked_list,5);
}

void test_print_linked_list(void)
{
    LinkedList linked_list;
    init_dummy_linked_list(&linked_list);
    print_linked_list(&linked_list);
    clear_linked_list(&linked_list);
}

int main(void)
{
    test_print_linked_list();
    return 0;
}
