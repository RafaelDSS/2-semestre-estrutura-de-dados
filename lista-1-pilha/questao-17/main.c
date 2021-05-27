#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_FIB 30


int fibbonacci(int n);

int main(void) {
    int value;
    Stack *stack = init_stack();
    
    for (int i = 0; i <= MAX_FIB; i++) {
        push(stack, fibbonacci(i));
    }

    value = pop(stack);
    while(value) {
        printf("%d\n", value);
        value = pop(stack);
    }
    return 0;
}

int fibbonacci(int n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return (fibbonacci(n - 1) + fibbonacci(n - 2));
}
