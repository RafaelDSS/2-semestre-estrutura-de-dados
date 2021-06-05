#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main(void) {
    char caracter;
    char *expression = "ESTE EXERCICIO E MUITO FACIL.";
    char string[40];

    Stack *stack1 = init_stack();
    Stack *stack2 = init_stack();
    Stack *stack3 = init_stack();

    push(stack1, ' ');
    while (*expression != '.') {
        push(stack1, *expression);
        expression++;
    }

    while(!is_empty(stack1)) {
        caracter = pop(stack1);
        if (caracter == ' ') {
            while(!is_empty(stack2)) {
                caracter = pop(stack2);
                push(stack3, caracter);
            }
            push(stack3, ' ');
        } else 
            push(stack2, caracter);
    }

    while(!is_empty(stack3))
        printf("%c", pop(stack3));
    printf("\n");

    return 0;
}
