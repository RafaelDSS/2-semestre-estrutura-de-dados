#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void) {
    Queue *queue = init_queue();
    int queue_length,
        value, 
        bigger = 0, 
        smaller = 0,
        sum = 0;

    enqueue(queue, 5);
    enqueue(queue, 7);
    enqueue(queue, 1);
    enqueue(queue, 4);

    queue_length = size_queue(queue);
    smaller = front_queue(queue);

    while(!queue_is_empty(queue)) {
        value = dequeue(queue);
        
        if (value > bigger)
            bigger = value;
        if (value < smaller)
            smaller = value;
        sum += value;
    }

    printf("O menor valor da fila é: %d\n", smaller);
    printf("O maior valor da fila é: %d\n", bigger);
    printf("A média é: %.2f\n", sum / (float)queue_length);

    return 0;
}