//
// Created by ajay on 10/16/22.
//
#include "circular_list.h"

CircularList* get_dummy_circular_list(void)
{
    CircularList* new_circular_list = get_new_circular_list();
    insert_at_head(new_circular_list, 5);
    insert_at_head(new_circular_list, 4);
    insert_at_head(new_circular_list, 3);
    insert_at_head(new_circular_list, 2);
    insert_at_head(new_circular_list, 1);
    return new_circular_list;
}

void test_print_circular_list(void)
{
    CircularList* new_circular_list = get_dummy_circular_list();
    print_circular_list(new_circular_list);
    //clear_circular_list(new_circular_list);
}

int main(void)
{
    test_print_circular_list();
    return 0;
}
