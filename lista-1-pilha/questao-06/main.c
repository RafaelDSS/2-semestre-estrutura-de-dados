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

    while (*expression != '.') {
        push(stack1, *expression);
        expression++;
    }

    caracter = pop(stack1);
    while(caracter) {
        if (caracter == ' ') {
            caracter = pop(stack2);
            while(caracter) {
                push(stack3, caracter);
                caracter = pop(stack2);
            }
            push(stack3, ' ');
        } else 
            push(stack2, caracter);
        caracter = pop(stack1);
    }

    caracter = pop(stack2);
    while(caracter) {
        push(stack3, caracter);
        caracter = pop(stack2);
    }

    caracter = pop(stack3);
    while(caracter) {
        printf("%c", caracter);
        caracter = pop(stack3);
    }
    printf("\n");

    return 0;
}
