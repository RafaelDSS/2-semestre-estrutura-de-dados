#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int f1_maior_que_f2(Queue *f1, Queue *f2);

int main(void) {
    Queue *f1 = init_queue();
    Queue *f2 = init_queue();

    enqueue(f1, 2);
    enqueue(f1, 4);
    enqueue(f1, 34);
    enqueue(f1, 8);

    enqueue(f2, 4);
    enqueue(f2, 3);
    enqueue(f2, 64);
    enqueue(f2, 5);
    enqueue(f2, 5);

    if (f1_maior_que_f2(f1, f2))
        printf("F1 é maior que F2\n");
    else
        printf("F1 não é maior que F2\n");

    return 0;
}

int f1_maior_que_f2(Queue *f1, Queue *f2) {
    return size_queue(f1) > size_queue(f2);
}
