//
// Created by ajay on 10/16/22.
//
#include "xor_list.h"
#include <stdio.h>

void init_dummy_xor_list(XORList* xor_list)
{
    init_xor_list(xor_list);
    insert_after_tail(xor_list, 1);
    insert_after_tail(xor_list, 2);
    insert_after_tail(xor_list, 3);
    insert_after_tail(xor_list, 4);
    insert_after_tail(xor_list, 4 + 1);
}

void test_print_xor_list(void)
{
    XORList xor_list;
    init_dummy_xor_list(&xor_list);
    print_xor_list(&xor_list);
    // clear_xor_list(&xor_list);
}

void test_delete_head(void)
{
    XORList xor_list;
    init_dummy_xor_list(&xor_list);
    printf("Before:-\n");
    print_xor_list(&xor_list);
    printf("After deleting head:-\n");
    delete_head(&xor_list);
    print_xor_list(&xor_list);
}

void test_delete_tail(void)
{
    XORList xor_list;
    init_dummy_xor_list(&xor_list);
    printf("Before:-\n");
    print_xor_list(&xor_list);
    printf("After deleting tail:-\n");
    delete_tail(&xor_list);
    print_xor_list(&xor_list);
}

void test_delete_at(void)
{
    XORList xor_list;
    init_dummy_xor_list(&xor_list);
    printf("Before:-\n");
    print_xor_list(&xor_list);
    printf("After deleting at index 2:-\n");
    delete_at(&xor_list, 2);
    print_xor_list(&xor_list);
}

int main(void)
{
    test_delete_at();
    return 0;
}
