#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void transfer_stack(Stack *p1, Stack *p2);

int main(void) {
    Stack *p1 = init_stack();
    Stack *p2 = init_stack();

    push(p1, 5);
    push(p1, 7);
    push(p1, 1);
    push(p1, 4);

    transfer_stack(p1, p2);

    return 0;
}

void transfer_stack(Stack *p1, Stack *p2) {
    int value;
    Stack *p3 = init_stack();

    value = pop(p1);
    while(value) {
        push(p3, value);
        value = pop(p1);
    }

    value = pop(p3);
    while(value) {
        push(p2, value);
        value = pop(p3);
    }
}
