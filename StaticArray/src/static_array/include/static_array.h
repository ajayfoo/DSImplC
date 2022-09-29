#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <stdbool.h>

#define STATIC_ARRAY_CAPACITY 100

typedef struct
{
    int length;
    int data[STATIC_ARRAY_CAPACITY];
} StaticArray;


bool insert(StaticArray* array, int ele);

bool insert_at(StaticArray* array, int index, int ele);

void print_array(const StaticArray* array);

void update(StaticArray* array, int index, int new_ele);

bool delete(StaticArray* array, int index);

#endif