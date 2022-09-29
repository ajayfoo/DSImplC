//
// Created by ajay on 9/17/22.
//
#include "static_array.h"
#include <stdio.h>

int main()
{
    StaticArray static_array = {0};
    insert(&static_array, 8);
    insert(&static_array, 10);
    insert(&static_array, 9);
    insert(&static_array, 1);
    insert(&static_array, 2);
    print_array(&static_array);
    update(&static_array, 2, 69);
    printf("After updating\n");
    print_array(&static_array);
    delete(&static_array, 2);
    printf("After deleting\n");
    print_array(&static_array);
    insert_at(&static_array, 2, 67);
    printf("After inserting at index 2.\n");
    print_array(&static_array);
}