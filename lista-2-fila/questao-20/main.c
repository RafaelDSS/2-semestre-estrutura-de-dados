#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int queue_pares(Queue *queue);

int main(void) {
    Queue *f1 = init_queue();

    enqueue(f1, 10);
    enqueue(f1, 20);
    enqueue(f1, 30);
    enqueue(f1, 45);
    enqueue(f1, 21);

    printf("Quantidade de números pares da Fila: %d\n", queue_pares(f1));

    return 0;
}

int queue_pares(Queue *queue) {
    int qt_pares = 0;

    while (!queue_is_empty(queue)) {
        if (dequeue(queue) % 2 == 0)
            qt_pares++;
    }
    return qt_pares;
}
