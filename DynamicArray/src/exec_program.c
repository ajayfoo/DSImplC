
#include "dynamic_array.h"
#include <stdlib.h>

int main()
{
    DynamicArray* dynamicArray = NULL;
    init_dynamic_array(dynamicArray);
    insert(dynamicArray, 8);
    print_array(dynamicArray);
    return 0;
}
