#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    int value, is_changed;;
    Stack *stack = init_stack();

    push(stack, 1);
    push(stack, 5);
    push(stack, 7);
    push(stack, 2);
    push(stack, 97);
    push(stack, 65);
    push(stack, 24);

    for (int i = 0; i < size_stack(stack); i++) {
        is_changed = 0;
        for (int j = 0; j < size_stack(stack)-1; j++) {
            int aux;

            if (stack->values[j] > stack->values[j+1]) {
                aux = stack->values[j];
                stack->values[j] = stack->values[j + 1];
                stack->values[j + 1] = aux;
                is_changed = 1;
            }
        }
        if (!is_changed)
            break;
    }

    value = pop(stack);
    while(value) {
        printf("%d\n", value);
        value = pop(stack);
    }
    return 0;
}