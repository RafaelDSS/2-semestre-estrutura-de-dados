#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main(void) {
    int is_valid = 1;
    char caracter;
    char expression[30] = "ararad";
    Stack *stack = init_stack();

    for (int i = 0; i < strlen(expression); i++) {
        push(stack, expression[i]);
    }

    for (int i = 0; i < strlen(expression); i++) {
        caracter = pop(stack);

        if (caracter != expression[i]) {
            is_valid = 0;
            break;
        }
    }

    if (is_valid)
        printf("É um palindromo!\n");
    else
        printf("Não é um palindromo!\n");

    return 0;
}
