//
// Created by ajay on 9/30/22.
//
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack* init_stack(size_t capacity)
{
    Stack* stack= (Stack*)malloc(sizeof(Stack)+(sizeof(int)*capacity));
    if(stack==NULL)
    {
        printf("Unable to allocate memory for Stack\n");
        abort();
    }
    stack->m_capacity=capacity;
    stack->m_top=-1;
    return stack;
}

void push(Stack* stack, int ele)
{
    if(stack->m_top==stack->m_capacity-1)
    {
        printf("Stack overflow occurred!\n");
        free(stack);
        abort();
    }
    stack->m_data[++stack->m_top]=ele;
}
int pop(Stack* stack)
{
    if(stack->m_top==-1)
    {
        printf("Stack underflow occurred!\n");
        free(stack);
        abort();
    }
    return stack->m_data[stack->m_top--];
}
int peek(Stack* stack)
{
    if(stack->m_top==-1)
    {
        printf("Stack is empty\n");
        free(stack);
        abort();
    }
    return stack->m_data[stack->m_top];
}
void print_stack(Stack* stack)
{
    printf("Stack Top: %d, Capacity: %zu\n",stack->m_top,stack->m_capacity);
    for(int i=stack->m_top;i>=0;--i)
    {
        printf("%d\n",stack->m_data[i]);
    }
}