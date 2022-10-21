//
// Created by ajay on 10/15/22.
//

#include "static_array.h"

void init_dummy_static_array(StaticArray* static_array)
{
    init_static_array(static_array);
    insert(static_array,1);
    insert(static_array,2);
    insert(static_array,3);
    insert(static_array,4);
    insert(static_array,5);
}

void test_print_array(void)
{
    StaticArray static_array;
    init_dummy_static_array(&static_array);
    print_array(&static_array);
}

int main(void)
{
    test_print_array();
    return 0;
}
