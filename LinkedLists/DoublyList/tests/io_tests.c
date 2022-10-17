//
// Created by ajay on 10/16/22.
//
#include "doubly_list.h"

void test_print_doubly_list(void)
{
    DoublyList* new_doubly_list = get_dummy_doubly_list();
    print_doubly_list(new_doubly_list);
    clear_doubly_list(new_doubly_list);
}

int main(void)
{
    test_print_doubly_list();
    return 0;
}
