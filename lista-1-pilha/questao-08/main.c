#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main(void) {
    Stack *stack = init_stack();
    int is_valid=1;

    char expressao[60] = "( ( ) ) – ( ( )( ) ) – ( ) ( )";

    for (int i=0; i < strlen(expressao); i++) {
        char caracter = expressao[i];
        if (caracter == '(')
            push(stack, caracter);
        else if (caracter == ')') {
            if (!pop(stack)) {
                is_valid = 0;
                break;
            }
        }
    }

    if (is_empty(stack) && is_valid) {
        printf("Expressão válida!\n");
    } else {
        printf("Expressão inválida!\n");
    }

    return 0;
}