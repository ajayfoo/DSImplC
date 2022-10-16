//
// Created by ajay on 10/15/22.
//
#include "stack.h"

Stack* get_dummy_stack(void)
{
    Stack* new_stack= init_stack(5);
    push(new_stack,10);
    push(new_stack,8);
    push(new_stack,6);
    push(new_stack,4);
    push(new_stack,2);
    return new_stack;
}

void test_print_stack(void)
{
    Stack* new_stack=get_dummy_stack();
    print_stack(new_stack);
}
int main(void)
{
    test_print_stack();
    return 0;
}
