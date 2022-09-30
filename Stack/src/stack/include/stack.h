//
// Created by ajay on 9/30/22.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    int m_top;
    size_t m_capacity;
    int m_data[];
} Stack;

Stack* init_stack(size_t capacity);
void push(Stack* stack,int ele);
int pop(Stack* stack);
int peek(Stack* stack);
void print_stack(Stack* stack);

#endif //STACK_STACK_H
