//
// Created by ajay on 10/16/22.
//
#include "linked_list.h"

LinkedList* get_dummy_linked_list(void)
{
    LinkedList* new_linked_list=get_new_linked_list();
    insert_after_tail(new_linked_list,1);
    insert_after_tail(new_linked_list,2);
    insert_after_tail(new_linked_list,3);
    insert_after_tail(new_linked_list,4);
    insert_after_tail(new_linked_list,5);
    return new_linked_list;
}

void test_print_linked_list(void)
{
    LinkedList* new_linked_list=get_dummy_linked_list();
    print_linked_list(new_linked_list);
    clear_linked_list(new_linked_list);
}

int main(void)
{
    test_print_linked_list();
    return 0;
}
