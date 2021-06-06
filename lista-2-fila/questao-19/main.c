#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int queue_impares(Queue *queue);

int main(void) {
    Queue *f1 = init_queue();

    enqueue(f1, 10);
    enqueue(f1, 20);
    enqueue(f1, 30);
    enqueue(f1, 45);
    enqueue(f1, 21);

    printf("Quantidade de números ímpares da Fila: %d\n", queue_impares(f1));

    return 0;
}

int queue_impares(Queue *queue) {
    int qt_impares = 0;

    while (!queue_is_empty(queue)) {
        if (dequeue(queue) % 2 != 0)
            qt_impares++;
    }
    return qt_impares;
}
