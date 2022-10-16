//
// Created by ajay on 10/15/22.
//
#include "dynamic_array.h"

DynamicArray* get_dummy_dynamic_array(void)
{
    DynamicArray* dynamic_array=NULL;
    dynamic_array= init_dynamic_array(dynamic_array);
    dynamic_array=insert(dynamic_array,1);
    dynamic_array=insert(dynamic_array,2);
    dynamic_array=insert(dynamic_array,3);
    dynamic_array=insert(dynamic_array,5);
    dynamic_array=insert(dynamic_array,5);
    return dynamic_array;
}

void test_print_array(void)
{
    DynamicArray* dynamic_array=get_dummy_dynamic_array();
    print_array(dynamic_array);
}
int main(void)
{
    test_print_array();
    return 0;
}
