#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    char value;
    int qt_l = 0, 
        qt_e = 0;
    Stack *stack = init_stack();

    push(stack, 'L');
    push(stack, 'L');
    push(stack, 'E');
    push(stack, 'E');

    value = pop(stack);
    while(value) {

        switch(value) {
            case 'L':
                qt_l++;
                break;
            case 'E':
                qt_e++;
                break;
        }
        value = pop(stack);
    }

    if (qt_l == qt_e)
        printf("Sequência válida!\n");
    else
        printf("Sequência inválida!\n");

    return 0;
}