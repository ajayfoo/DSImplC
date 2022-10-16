//
// Created by ajay on 9/28/22.
//

#ifndef DYNAMICARRAY_DYNAMIC_ARRAY_H
#define DYNAMICARRAY_DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>


typedef struct
{
    size_t m_length;
    size_t m_capacity;
    int m_data[];
} DynamicArray;

DynamicArray* insert(DynamicArray* array, int ele);

DynamicArray* insert_at(DynamicArray* array, size_t index, int ele);

int element_at(DynamicArray* array, size_t index);

int search(DynamicArray* array, int ele);

void print_array(const DynamicArray* array);

DynamicArray* init_dynamic_array(DynamicArray* dynamic_array);

void update(DynamicArray* array, size_t index, int new_ele);

DynamicArray* delete_element_at(DynamicArray* array, size_t index);

#endif //DYNAMICARRAY_DYNAMIC_ARRAY_H
