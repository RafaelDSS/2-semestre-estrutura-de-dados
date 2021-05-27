#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    int value;
    Stack *stack = init_stack();

    push(stack, 10);
    push(stack, 20);
    pop(stack);
    push(stack, 30);
    push(stack, 45);
    push(stack, 21);
    pop(stack);
    pop(stack);

    value = pop(stack);
    while(value) {
        printf("%d\n", value);
        value = pop(stack);
    }
    return 0;
}