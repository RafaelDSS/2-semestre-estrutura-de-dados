#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    int value, 
        odds_qt = 0;
    Stack *p1 = init_stack();

    push(p1, 7);
    push(p1, 8);
    push(p1, 4);
    push(p1, 5);

    value = pop(p1);
    while(value) {
        if (value % 2 != 0)
            odds_qt++;
        value = pop(p1);
    }
    printf("A pilha possue %d valores ímpares!\n", odds_qt);

    return 0;
}