#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void stack_maior(Stack *p1, Stack *p2);

int main(void) {
    int value;
    Stack *p1 = init_stack();
    Stack *p2 = init_stack();

    push(p1, 5);
    push(p1, 7);
    push(p1, 1);
    push(p1, 4);
    push(p1, 4);

    push(p2, 5);
    push(p2, 7);
    push(p2, 1);
    push(p2, 4);

    stack_maior(p1, p2);

    return 0;
}

void stack_maior(Stack *p1, Stack *p2) {
    if (size_stack(p1) > size_stack(p2))
        printf("P1 é maior que P2\n");
    else
        printf("P1 não é maior P2\n");
}
