//
// Created by ajay on 10/15/22.
//

#include "static_array.h"

StaticArray get_dummy_static_array(void)
{
    StaticArray static_array;
    insert(&static_array,1);
    insert(&static_array,2);
    insert(&static_array,3);
    insert(&static_array,4);
    insert(&static_array,5);
    return static_array;
}

void test_print_array(void)
{
    StaticArray static_array=get_dummy_static_array();
    print_array(&static_array);
}

int main(void)
{
    test_print_array();
    return 0;
}
