//
// Created by ajay on 9/28/22.
//
#include "dynamic_array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EXTRA_SPACE_FOR_ARRAY 10


bool array_is_full(DynamicArray* array)
{
    return array->m_length == array->m_capacity;
}

void copy_array(DynamicArray* src_array, DynamicArray* array)
{
    array->m_length = src_array->m_length;
    for (int i = 0; i < src_array->m_length; ++i)
    {
        array->m_data[i] = src_array->m_data[i];
    }
}

DynamicArray* expand_array(DynamicArray* array)
{
    DynamicArray* new_array = (DynamicArray*) malloc(
            sizeof(DynamicArray) + (sizeof(int) * (array->m_capacity + EXTRA_SPACE_FOR_ARRAY)));
    if (new_array == NULL)
    {
        printf("Failed to allocate memory for array\n");
        return array;
    }
    new_array->m_capacity = array->m_capacity + EXTRA_SPACE_FOR_ARRAY;
    copy_array(array, new_array);
    free(array);
    return new_array;
}

DynamicArray* init_dynamic_array(DynamicArray* dynamicArray)
{
    dynamicArray = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (dynamicArray == NULL)
    {
        printf("Failed to allocate memory for array\n");
        return dynamicArray;
    }
    dynamicArray->m_length = 0;
    dynamicArray->m_capacity = 0;
    return dynamicArray;
}

DynamicArray* insert(DynamicArray* array, int ele)
{
    if (array_is_full(array))
    {
        array = expand_array(array);
    }
    array->m_data[array->m_length] = ele;
    ++array->m_length;
    return array;
}

// read
void print_array(const DynamicArray* array)
{
    for (int i = 0; i < array->m_length; ++i)
    {
        printf("StaticArray[%d]: %d\n", i, array->m_data[i]);
    }
}