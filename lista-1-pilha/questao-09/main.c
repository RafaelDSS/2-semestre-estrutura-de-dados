#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void sort_stack(Stack *stack);

int main(void) {
    Stack *stack = init_stack();

    push(stack, 1);
    push(stack, 5);
    push(stack, 7);
    push(stack, 2);
    push(stack, 97);
    push(stack, 65);
    push(stack, 24);

    sort_stack(stack);

    while(!is_empty(stack))
        printf("%d\n", pop(stack));
}

void sort_stack(Stack *stack) {
    Stack *aux_stack = init_stack();

    while (!is_empty(stack)) {
        int temp_value = pop(stack);

        while (!is_empty(aux_stack) && top_stack(aux_stack) > temp_value)
            push(stack, pop(aux_stack));
        push(aux_stack, temp_value);
    }
    while (!is_empty(aux_stack))
        push(stack, pop(aux_stack));
}
