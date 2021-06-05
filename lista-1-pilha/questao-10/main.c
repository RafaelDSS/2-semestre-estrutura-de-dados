#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    Stack *stack = init_stack();
    int stack_length,
        value, 
        bigger = 0, 
        smaller = 0,
        sum = 0;

    push(stack, 5);
    push(stack, 7);
    push(stack, 1);
    push(stack, 4);

    stack_length = size_stack(stack);
    smaller = top_stack(stack);

    while(!is_empty(stack)) {
        value = pop(stack);
        
        if (value > bigger)
            bigger = value;
        if (value < smaller)
            smaller = value;
        sum += value;
    }

    printf("O menor valor da pilha é: %d\n", smaller);
    printf("O maior valor da pilha é: %d\n", bigger);
    printf("A média é: %.2f\n", sum / (float)stack_length);

    return 0;
}