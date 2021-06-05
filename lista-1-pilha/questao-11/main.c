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
    Stack *p2 = init_stack();

    while(!is_empty(p1))                                                                                                                                                                                                                                                                                                                                                                                                                                
        push(p2, pop(p1));                                                 

    while(!is_empty(p2))
        printf("%d\n", pop(p2));
}
