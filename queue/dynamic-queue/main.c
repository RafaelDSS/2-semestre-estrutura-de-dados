#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


int main(void) {
    Queue queue = {NULL};


    Aluno aluno1 = {
        .matricula = "adjahdadadh",
        .nome = "Alunos 13838",
        .notas = {4,5,3}
    };
    enqueue(&queue, aluno1);
    
    Aluno aluno2 = {
        .matricula = "adjahdadadh",
        .nome = "Aluno 8383",
        .notas = {4,5,3}
    };
    enqueue(&queue, aluno2);
    
    Aluno aluno3 = {
        .matricula = "adjahdadadh",
        .nome = "Aluno 8888383",
        .notas = {4,5,3}
    };
    enqueue(&queue, aluno3);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
}
