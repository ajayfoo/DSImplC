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
    int* m_data;
} DynamicArray;

int element_at(DynamicArray* array, int index);

void insert(DynamicArray* array, int ele);

bool insert_at(DynamicArray* array, int index, int ele);

void print_array(const DynamicArray* array);

void update(DynamicArray* array, int index, int new_ele);

bool delete(DynamicArray* array, int index);

DynamicArray* init_dynamic_array(DynamicArray* array);

#endif //DYNAMICARRAY_DYNAMIC_ARRAY_H
