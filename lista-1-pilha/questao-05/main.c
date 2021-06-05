#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int verify_pattern(char x[], char y[]);

int main(void) {
    Stack *p1 = init_stack();
    char x[20],
         y[20],
         expression[30] = "ABCDDCBA";
    int stack_length,
        is_valid = 1;


    for (int i = 0; i < strlen(expression); i++) {
        push(p1, expression[i]);
    }
    stack_length = size_stack(p1);

    if (stack_length % 2 != 0) {
        is_valid = 0;
    } else {
        for (int i = 0; i < (stack_length / 2); i++) {
            x[i] = pop(p1);
            x[i+1] = '\0';
        }
        for (int i = 0; i < (stack_length / 2); i++) {
            y[i] = pop(p1);
            y[i+1] = '\0';
        }
    }

    if (is_valid && verify_pattern(x, y))
        printf("A string está no padrão XY, X=%s, Y=%s.\n", x, y);
    else
        printf("A string não está no padrão XY.\n");

    return 0;
}

int verify_pattern(char x[], char y[]) {
    for (int i = 0, j = strlen(x)-1; i < strlen(x); i++, j--) {
        if (x[i] != y[j])
            return 0;
    }
    return 1;
}
