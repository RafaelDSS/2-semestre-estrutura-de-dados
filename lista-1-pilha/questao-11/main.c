#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void reverse_stack(Stack *p1);

int main(void) {
    Stack *p1 = init_stack();

    push(p1, 5);
    push(p1, 7);
    push(p1, 1);
    push(p1, 4);

    reverse_stack(p1);

    return 0;
}

void reverse_stack(Stack *p1) {
    int value;
    Stack *p2 = init_stack();

    value = pop(p1);
    while(value) {
        push(p2, value);
        value = pop(p1);
    }

    value = pop(p2);
    while(value) {
        printf("%d\n", value);
        value = pop(p2);
    }
}
