//
// Created by ajay on 10/16/22.
//
#include "xor_list.h"

void init_dummy_xor_list(XORList* xor_list)
{
    init_xor_list(xor_list);
    insert_after_tail(xor_list, 1);
    insert_after_tail(xor_list, 2);
    insert_after_tail(xor_list, 3);
    insert_after_tail(xor_list, 4);
    insert_after_tail(xor_list, 4 + 1);
    insert_at(xor_list, 2, 4 * 4);
}

void test_print_xor_list(void)
{
    XORList xor_list;
    init_dummy_xor_list(&xor_list);
    print_xor_list(&xor_list);
    // clear_xor_list(&xor_list);
}

int main(void)
{
    test_print_xor_list();
    return 0;
}
