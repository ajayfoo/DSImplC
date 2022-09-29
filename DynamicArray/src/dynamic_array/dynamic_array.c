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
    array->m_capacity = src_array->m_capacity;
    for (int i = 0; i < src_array->m_length; ++i)
    {
        array->m_data[i] = src_array->m_data[i];
    }
}

DynamicArray* expand_array(DynamicArray* array)
{
    DynamicArray* new_array = malloc(
            sizeof(DynamicArray) + (sizeof(int) * (array->m_capacity + EXTRA_SPACE_FOR_ARRAY)));
    new_array->m_capacity = array->m_capacity + EXTRA_SPACE_FOR_ARRAY;
    copy_array(array, new_array);
    free(array);
    return new_array;
}

DynamicArray* init_dynamic_array(DynamicArray* dynamicArray)
{
    dynamicArray = malloc(sizeof(DynamicArray));
    dynamicArray->m_length = 0;
    dynamicArray->m_capacity = 0;
    return dynamicArray;
}

//create
int element_at(DynamicArray* dynamicArray, int index)
{
    return dynamicArray->m_data[index];
}

void insert(DynamicArray* array, int ele)
{
    if (array_is_full(array))
    {
        array = expand_array(array);
    }
    array->m_data[array->m_length] = ele;
    ++array->m_length;
}

bool insert_at(DynamicArray* array, int index, int ele)
{
    if (array_is_full(array))
    {
        printf("Array is full!\n");
        return false;
    } else
    {
        for (int i = array->m_length - 1; i > index; --i)
        {
            array->m_data[i] = array->m_data[i - 1];
        }
        array->m_data[index] = ele;
        ++array->m_length;
        return true;
    }
}

// read
void print_array(const DynamicArray* array)
{
    for (int i = 0; i < array->m_length; ++i)
    {
        printf("StaticArray[%d]: %d\n", i, array->m_data[i]);
    }
}

//update

void update(DynamicArray* array, int index, int new_ele)
{
    if (index < 0 || index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
    } else
    {
        array->m_data[index] = new_ele;
    }
}

//delete

bool delete(DynamicArray* array, int index)
{
    if (index < 0 || index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
        return false;
    } else
    {
        for (int i = index; i < (array->m_length - 1); ++i)
        {
            array->m_data[i] = array->m_data[i + 1];
        }
        --array->m_length;
    }
}