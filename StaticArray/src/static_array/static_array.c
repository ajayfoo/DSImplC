#include "static_array.h"
#include <stdbool.h>
#include <stdio.h>

bool array_is_full(const StaticArray* array)
{
    return STATIC_ARRAY_CAPACITY == array->length;
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
        array->data[array->length] = ele;
        ++array->length;
        return true;
    }
}

bool insert_at(StaticArray* array, int index, int ele)
{
    if (array_is_full(array))
    {
        printf("Array is full!\n");
        return false;
    } else
    {
        for (int i = array->length - 1; i > index; --i)
        {
            array->data[i] = array->data[i - 1];
        }
        array->data[index] = ele;
        ++array->length;
        return true;
    }
}

// read
void print_array(const StaticArray* array)
{
    for (int i = 0; i < array->length; ++i)
    {
        printf("StaticArray[%d]: %d\n", i, array->data[i]);
    }
}

//update

void update(StaticArray* array, int index, int new_ele)
{
    if (index < 0 || index >= array->length)
    {
        printf("Array's index is out of bounds\n");
    } else
    {
        array->data[index] = new_ele;
    }
}

//delete

bool delete(StaticArray* array, int index)
{
    if (index < 0 || index >= array->length)
    {
        printf("Array's index is out of bounds\n");
        return false;
    } else
    {
        for (int i = index; i < (array->length - 1); ++i)
        {
            array->data[i] = array->data[i + 1];
        }
        --array->length;
    }
}