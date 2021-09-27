#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void) {
    List *list = init_list();

    Aluno *aluno;

    Aluno aluno1 = {
        .matricula = "adjahdadadh",
        .nome = "Alunos 13838",
        .notas = {4,5,3}
    };
    push_back(list, aluno1);
   
    aluno = get_at(list, 0);
    return 1;
}