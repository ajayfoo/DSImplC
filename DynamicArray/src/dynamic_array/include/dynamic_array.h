//
// Created by ajay on 9/28/22.
//

#ifndef DYNAMICARRAY_DYNAMIC_ARRAY_H
#define DYNAMICARRAY_DYNAMIC_ARRAY_H

#include <stdbool.h>


typedef struct
{
    int m_length;
    int m_capacity;
    int m_data[];
} DynamicArray;

DynamicArray* insert(DynamicArray* array, int ele);

void print_array(const DynamicArray* array);

DynamicArray* init_dynamic_array(DynamicArray* array);

#endif //DYNAMICARRAY_DYNAMIC_ARRAY_H
