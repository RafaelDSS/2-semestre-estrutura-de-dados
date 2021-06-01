#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "time.h"


int main(void) {
    Queue *queue = init_queue();
    
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        Stack *stack = init_stack();

        for (int j = 0; j < 4; j++) {
            push(stack, rand() % 100);
        }
        enqueue(queue, stack);
    }

    for (int i = 0; i < 10; i++) {
        Stack *stack = dequeue(queue);

        printf("dequeue() - Pilha %d:\n", i+1);
        for (int j = 0; j < 4; j++) {
            printf("\tpop() == %d\n", pop(stack));
        }
    }    
    return 0;
}
