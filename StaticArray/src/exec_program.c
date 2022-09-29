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
    printf("Element 3 is at index %d\n", search(&static_array,3));
    return 0;
}