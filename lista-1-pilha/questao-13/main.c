#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void stack_compare(Stack *p1, Stack *p2);

int main(void) {
    int value;
    Stack *p1 = init_stack();
    Stack *p2 = init_stack();

    push(p1, 5);
    push(p1, 7);
    push(p1, 1);
    push(p1, 4);

    push(p2, 5);
    push(p2, 7);
    push(p2, 1);
    push(p2, 4);

    stack_compare(p1, p2);

    return 0;
}

void stack_compare(Stack *p1, Stack *p2) {
    int is_valid = 1;

    if (size_stack(p1) != size_stack(p2))
        is_valid = 0;
    else {
        for (int i = 0; i < size_stack(p1); i++) {
            if (pop(p1) != pop(p2)) {
                is_valid = 0;
                break;
            }
        }
    }
    if (is_valid)
        printf("As duas pilhas são iguais!\n");
    else
        printf("As duas pilhas não são iguais!\n");
}
