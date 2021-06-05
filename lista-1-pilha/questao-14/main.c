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
    Stack *p3 = init_stack();

    while(!is_empty(p1))
        push(p3, pop(p1));

    while(!is_empty(p3))
        push(p2, pop(p3));
}
