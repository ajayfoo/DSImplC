
#include "dynamic_array.h"
#include <stdlib.h>

int main()
{
    DynamicArray* dynamicArray = NULL;
    dynamicArray = init_dynamic_array(dynamicArray);
    dynamicArray = insert(dynamicArray, 8);
    dynamicArray = insert(dynamicArray, 10);
    dynamicArray = insert(dynamicArray, 12);
    print_array(dynamicArray);
    return 0;
}
