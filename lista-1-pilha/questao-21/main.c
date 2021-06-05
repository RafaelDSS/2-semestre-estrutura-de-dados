#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    Stack *stack = init_stack();

    push(stack, 10);
    push(stack, 20);
    pop(stack);
    push(stack, 30);
    push(stack, 45);
    push(stack, 21);
    pop(stack);
    pop(stack);

    while(!is_empty(stack))
        printf("%d\n", pop(stack));

    return 0;
}