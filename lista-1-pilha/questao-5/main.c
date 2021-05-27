#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


char *stack_to_string(Stack *stack);

int main(void) {
    char *string1, *string2;
    char expression[30] = "ABCDDCBADE";
    int exp_length = strlen(expression);
    int is_valid = 1;

    Stack *stack1 = init_stack();
    Stack *stack2 = init_stack();

    if (exp_length % 2 != 0) {
        is_valid = 0;
    } else {
        for (int x = 0, y = exp_length-1; x < (exp_length / 2); x++, y--) {
            push(stack1, expression[x]);
            push(stack2, expression[y]);
        }
        string1 = stack_to_string(stack1);
        string2 = stack_to_string(stack2);

        if (strncmp(string1, string2, 30) != 0)
            is_valid = 0;
    }

    if (is_valid)
        printf("A string está no padrão XY.\n");
    else
        printf("A string não está no padrão XY.\n");

    return 0;
}

char *stack_to_string(Stack *stack) {
    char value;
    int index=0;
    char *string = (char *)malloc(sizeof(char) * 30);

    value = pop(stack);
    while(value) {
        string[index++] = value;
        value = pop(stack);
    }
    return string;
}