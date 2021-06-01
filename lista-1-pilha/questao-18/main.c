#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"


int main(void) {
    Queue *queue_par = init_queue();
    Queue *queue_impar = init_queue();
    Stack *stack = init_stack();

    int lenght_stack;
    int input = 1;

    while (input) {
        printf("Digite um número inteiro ou 0 para encerrar: ");
        scanf("%d", &input);

        if (input % 2 == 0)
            enqueue(queue_par, input);
        else 
            enqueue(queue_impar, input);
    }

    while (!queue_is_empty(queue_impar) || !queue_is_empty(queue_par)) {
        if (!queue_is_empty(queue_impar)) {
            int value = dequeue(queue_impar);

            if (value > 0) {
                push(stack, value);
            } else {
                pop(stack);
            }
        } 
        if (!queue_is_empty(queue_par)) {
            int value = dequeue(queue_par);

            if (value > 0) {
                push(stack, value);
            } else {
                pop(stack);
            }
        }
    }
    lenght_stack = size_stack(stack);
    for (int i = 0; i < lenght_stack; i++) {
        printf("Stack - pop(): %d\n", pop(stack));
    }
    return 0;
}