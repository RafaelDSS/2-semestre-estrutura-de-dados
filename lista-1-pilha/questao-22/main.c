#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int stack_top(Stack *p1);

int main(void) {
    Stack *stack = init_stack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 45);
    push(stack, 21);

    printf("Valor do topo da Pilha é: %d\n", stack_top(stack));
    return 0;
}

int stack_top(Stack *p1) {
    return pop(p1);
}
