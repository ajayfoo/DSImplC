#include "static_array.h"
#include <stdbool.h>
#include <stdio.h>

bool array_is_full(const StaticArray* array)
{
    return STATIC_ARRAY_CAPACITY == array->m_length;
}

//create

bool insert(StaticArray* array, int ele)
{
    if (array_is_full(array))
    {
        printf("Array is full!\n");
        return false;
    } else
    {
        array->m_data[array->m_length] = ele;
        ++array->m_length;
        return true;
    }
}

bool insert_at(StaticArray* array, size_t index, int ele)
{
    if (array_is_full(array))
    {
        printf("Array is full!\n");
        return false;
    } else
    {
        ++array->m_length;
        for (size_t i = array->m_length; i > index; --i)
        {
            array->m_data[i] = array->m_data[i - 1];
        }
        array->m_data[index] = ele;
        return true;
    }
}

// read
void print_array(const StaticArray* array)
{
    for (int i = 0; i < array->m_length; ++i)
    {
        printf("StaticArray[%d]: %d\n", i, array->m_data[i]);
    }
}

int search(StaticArray* array, int ele)
{
    for(size_t i=0;i<array->m_length;++i)
    {
        if(array->m_data[i]==ele)return (int)i;
    }
    return -1;
}
//update

void update(StaticArray* array, size_t index, int new_ele)
{
    if (index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
    } else
    {
        array->m_data[index] = new_ele;
    }
}

//delete

bool delete(StaticArray* array, size_t index)
{
    if (index >= array->m_length)
    {
        printf("Array's index is out of bounds\n");
        return false;
    } else
    {
        for (size_t i = index; i < (array->m_length - 1); ++i)
        {
            array->m_data[i] = array->m_data[i + 1];
        }
        --array->m_length;
        return true;
    }
}