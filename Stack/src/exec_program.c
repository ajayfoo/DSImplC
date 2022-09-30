#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Stack* stack= init_stack(3);
    push(stack,9);
    push(stack,10);
    push(stack,11);
    print_stack(stack);
    printf("First pop: %d\n",pop(stack));
    print_stack(stack);
    printf("Peek: %d\n", peek(stack));
    free(stack);
    return 0;
}
