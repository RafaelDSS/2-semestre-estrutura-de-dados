#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    Stack *stack = init_stack();
    int qt_l = 0, qt_e = 0;

    push(stack, 'L');
    push(stack, 'L');
    push(stack, 'E');
    push(stack, 'E');

    while(!is_empty(stack)) {
        char value = pop(stack);

        switch(value) {
            case 'L':
                qt_l++;
                break;
            case 'E':
                qt_e++;
                break;
        }
    }

    if (qt_l == qt_e)
        printf("Sequência válida!\n");
    else
        printf("Sequência inválida!\n");

    return 0;
}