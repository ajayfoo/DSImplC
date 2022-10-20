//
// Created by ajay on 10/16/22.
//
#include "doubly_list.h"


void init_dummy_doubly_list(DoublyList* doubly_list)
{
    init_doubly_list(doubly_list);
    insert_after_tail(doubly_list, 1);
    insert_after_tail(doubly_list, 2);
    insert_after_tail(doubly_list, 3);
    insert_after_tail(doubly_list, 4);
    insert_after_tail(doubly_list, 5);
}


void test_print_doubly_list(void)
{
    DoublyList doubly_list;
    init_dummy_doubly_list(&doubly_list);
    print_doubly_list(&doubly_list);
    clear_doubly_list(&doubly_list);
}

int main(void)
{
    test_print_doubly_list();
    return 0;
}
