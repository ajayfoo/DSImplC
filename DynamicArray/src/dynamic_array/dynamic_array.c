//
// Created by ajay on 9/28/22.
//
#include "dynamic_array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EXTRA_SPACE_FOR_ARRAY 2


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
        abort();
    }
    new_array->m_capacity = array->m_capacity + EXTRA_SPACE_FOR_ARRAY;
    copy_array(array, new_array);
    free(array);
    return new_array;
}


DynamicArray* shrink_array(DynamicArray* array)
{
    DynamicArray* new_array = (DynamicArray*) malloc(
            sizeof(DynamicArray) + (sizeof(int) * (array->m_length + EXTRA_SPACE_FOR_ARRAY)));
    if (new_array == NULL)
    {
        printf("Failed to allocate memory for array\n");
        abort();
    }
    new_array->m_capacity = array->m_length + EXTRA_SPACE_FOR_ARRAY;
    copy_array(array, new_array);
    free(array);
    return new_array;
}


DynamicArray* init_dynamic_array(DynamicArray* dynamic_array)
{
    dynamic_array = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (dynamic_array == NULL)
    {
        printf("Failed to allocate memory for array\n");
        abort();
    }
    dynamic_array->m_length = 0;
    dynamic_array->m_capacity = 0;
    return dynamic_array;
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


DynamicArray* insert_at(DynamicArray* dynamic_array, size_t index, int ele)
{
    if (array_is_full(dynamic_array))
    {
        dynamic_array = expand_array(dynamic_array);
    }

    ++dynamic_array->m_length;
    for (size_t i = dynamic_array->m_length; i > index; --i)
    {
        dynamic_array->m_data[i] = dynamic_array->m_data[i - 1];
    }
    dynamic_array->m_data[index] = ele;
    return dynamic_array;
}

// read
void print_array(const DynamicArray* array)
{
    printf("Array Length: %zu, Capacity: %zu\n", array->m_length, array->m_capacity);
    for (int i = 0; i < array->m_length; ++i)
    {
        printf("StaticArray[%d]: %d\n", i, array->m_data[i]);
    }
}

int element_at(DynamicArray* array, size_t index)
{
    if (index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
        abort();
    }
    return array->m_data[index];
}

int search(DynamicArray* array, int ele)
{
    for (size_t i = 0; i < array->m_length; ++i)
    {
        if (array->m_data[i] == ele)return (int) i;
    }
    return -1;
}
//update

void update(DynamicArray* array, size_t index, int new_ele)
{
    if (index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
        abort();
    } else
    {
        array->m_data[index] = new_ele;
    }
}

//delete

DynamicArray* delete(DynamicArray* array, size_t index)
{
    if (index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
        abort();
    } else
    {
        for (size_t i = index; i < (array->m_length - 1); ++i)
        {
            array->m_data[i] = array->m_data[i + 1];
        }
        --array->m_length;
        if (array->m_capacity - array->m_length > EXTRA_SPACE_FOR_ARRAY * 2)
        {
            array = shrink_array(array);
        }
        return array;
    }
}