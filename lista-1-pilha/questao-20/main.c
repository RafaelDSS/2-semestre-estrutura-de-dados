#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    Stack stack = {NULL};
    
    push(&stack, 'A');
    push(&stack, 'C');
    push(&stack, 'B');

    push(&stack, 4);
    push(&stack, 87);
    push(&stack, 65);


    printf("Stack: %d\n", pop(&stack));
    printf("Stack: %d\n", pop(&stack));
    printf("Stack: %d\n", pop(&stack));
    printf("Stack: %c\n", pop(&stack));
    printf("Stack: %c\n", pop(&stack));
    printf("Stack: %c\n", pop(&stack));

    return 0;
}
