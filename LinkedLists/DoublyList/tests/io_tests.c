//
// Created by ajay on 10/16/22.
//
#include "doubly_list.h"

DoublyList* get_dummy_doubly_list(void)
{
    DoublyList* new_doubly_list=get_new_doubly_list();
    insert_after_tail(new_doubly_list,1);
    insert_after_tail(new_doubly_list,2);
    insert_after_tail(new_doubly_list,3);
    insert_after_tail(new_doubly_list,4);
    insert_after_tail(new_doubly_list,5);
    return new_doubly_list;
}

void test_print_doubly_list(void)
{
    DoublyList* new_doubly_list=get_dummy_doubly_list();
    print_doubly_list(new_doubly_list);
    clear_doubly_list(new_doubly_list);
}

int main(void)
{
    test_print_doubly_list();
    return 0;
}
