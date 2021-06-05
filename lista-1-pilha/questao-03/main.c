#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    int value;
    Stack *stack1 = init_stack();
    Stack *stack2 = init_stack();
    Stack *stack3 = init_stack();

    push(stack1, 1);
    push(stack1, 2);
    push(stack1, 3);
    push(stack1, 4);

    push(stack3, pop(stack1));
    push(stack3, pop(stack1));
    push(stack2, pop(stack1));
    push(stack1, pop(stack3));
    push(stack1, pop(stack3));
    push(stack1, pop(stack2));

    while (!is_empty(stack1))
        printf("%d\n", pop(stack1));

    return 0;
}