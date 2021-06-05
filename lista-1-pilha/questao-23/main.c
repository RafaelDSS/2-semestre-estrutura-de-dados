#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void) {
    Stack *p1 = init_stack();
    int odds_qt = 0;

    push(p1, 7);
    push(p1, 8);
    push(p1, 4);
    push(p1, 5);

    while(!is_empty(p1)) {
        if (pop(p1) % 2 != 0)
            odds_qt++;
    }
    printf("A pilha possue %d valores ímpares!\n", odds_qt);

    return 0;
}