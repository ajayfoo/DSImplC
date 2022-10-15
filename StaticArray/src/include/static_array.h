#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

#define STATIC_ARRAY_CAPACITY 100

typedef struct
{
    size_t m_length;
    int m_data[STATIC_ARRAY_CAPACITY];
} StaticArray;


bool insert(StaticArray* array, int ele);

bool insert_at(StaticArray* array, size_t index, int ele);

int element_at(StaticArray* array, size_t index);

int search(StaticArray* array, int ele);

void print_array(const StaticArray* array);

void update(StaticArray* array, size_t index, int new_ele);

bool delete_element_at(StaticArray* array, size_t index);

#endif