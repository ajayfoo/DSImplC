
#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    DynamicArray* dynamic_array = NULL;
    dynamic_array = init_dynamic_array(dynamic_array);
    dynamic_array = insert(dynamic_array, 8);
    dynamic_array = insert(dynamic_array, 10);
    dynamic_array = insert(dynamic_array, 12);
    dynamic_array = insert(dynamic_array, 14);
    dynamic_array = insert(dynamic_array, 16);
    print_array(dynamic_array);
    dynamic_array = delete(dynamic_array, 1);
    dynamic_array = delete(dynamic_array, 1);
    dynamic_array = delete(dynamic_array, 1);
    dynamic_array = delete(dynamic_array, 1);
    print_array(dynamic_array);
    update(dynamic_array, 0, 3);
    print_array(dynamic_array);
    free(dynamic_array);
    return 0;
}
