#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

void inserir_aluno(List *list);

void trocar_elementos(List *list);

void pesquisar_por_posicao(List *list);
void pesquisar_por_matricula(List *list);
void pesquisar_por_nome(List *list);

void remover_por_posicao(List *list);
void remover_por_matricula(List *list);
void remover_por_nome(List *list);

void remover_n_posicoes(List *list);

void copiar_lista_aprovados(List *list, List *list_aprovados);
void copiar_lista_reprovados(List *list, List *list_reprovados);

void mostrar_alunos(List *list);


int main(void) {
    List *list = init_list();
    List *list_aprovados = init_list();
    List *list_reprovados = init_list();
    int opcao = 1;

    while (opcao) {
        printf(
            "Digite uma das Opções\n"
            "\t[1]  - Inserir aluno\n"
            "\t[2]  - Consultar aluno por posição\n"
            "\t[3]  - Consultar aluno por matrícula\n"
            "\t[4]  - Consultar aluno por nome\n"
            "\t[5]  - Remover aluno por posição\n"
            "\t[6]  - Remover aluno por matrícula\n"
            "\t[7]  - Remover aluno por nome\n"
            "\t[8]  - Remover os N primeiros alunos\n"
            "\t[9]  - Trocar a posição de dois alunos\n"
            "\t[10] - Copiar os alunos aprovados para a lista de aprovados\n"
            "\t[11] - Copiar os alunos reprovados para a lista de reprovados\n"
            "\t[12] - Mostrar a lista de alunos aprovados\n"
            "\t[13] - Mostrar a lista de  alunos reprovados\n"
            "\t[14] - Mostrar todos os alunos\n"
            "\t[0]  - Sair\n"
            ">>> "
        );
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_aluno(list);
                break;
            case 2:
                pesquisar_por_posicao(list);
                break;
            case 3:
                pesquisar_por_matricula(list);
                break;
            case 4:
                pesquisar_por_nome(list);
                break;
            case 5:
                remover_por_posicao(list);
                break;
            case 6:
                remover_por_matricula(list);
                break;
            case 7:
                remover_por_nome(list);
                break;
            case 8:
                remover_n_posicoes(list);
                break;
            case 9:
                trocar_elementos(list);
                break;
            case 10:
                copiar_lista_aprovados(list, list_aprovados);
                break;
            case 11:
                copiar_lista_reprovados(list, list_reprovados);
                break;
            case 12:
                mostrar_alunos(list_aprovados);
                break;
            case 13:
                mostrar_alunos(list_reprovados);
                break;
            case 14:
                mostrar_alunos(list);
                break;
        }
    }

    return 1;
}

void mostra_aluno(Aluno *aluno, int position) {
    printf("=================================\n");
    printf("índice = %d:\n", position);
    printf("\tNome: %s\n", aluno->nome);
    printf("\tMatrícula: %s\n", aluno->matricula);

    for (int i = 0; i < 3; i++) {
        printf("\t%d° nota: %.2f\n", i+1, aluno->notas[i]);
    }
    free(aluno);
    printf("=================================\n");
}

void mostrar_alunos(List *list) {
    Aluno *aluno;
    int index = 0;

    while ((aluno = get_at(list, index)) != NULL) {
        mostra_aluno(aluno, index);
        index++;
    }
    if(!index)
        printf("A lista está vazia!\n");
    else 
        printf("Operação finalizada!\n");
}

void inserir_aluno(List *list) {
    Aluno aluno;

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);

    printf("Digite a matrícula do aluno: ");
    scanf("%s", aluno.matricula);

    for (int i = 0; i < 3; i++) {
        printf("Digite %d° do aluno: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }
    push_back(list, aluno);
    printf("Operação finalizada!\n");
}

void trocar_elementos(List *list) {
    Aluno *aluno1, *aluno2;
    int pos1, pos2;

    mostrar_alunos(list);
    printf("\nDigite um dos índices listados acima: ");
    scanf("%d", &pos1);

    printf("Digite um dos índices listados acima: ");
    scanf("%d", &pos2);
    
    aluno1 = get_at(list, pos1);
    aluno2 = get_at(list, pos2);

    if (aluno1 != NULL && aluno2 != NULL) {
        remove_at(list, pos1);
        insert_at(list, pos1, *aluno2);

        remove_at(list, pos2);
        insert_at(list, pos2, *aluno1);

        free(aluno1);
        free(aluno2);
        printf("Operação finalizada!\n");
    }
    else
        printf("Não foi prossivel fazer a troca\n");


}

void pesquisar_por_posicao(List *list) {
    Aluno *aluno;
    int pos;

    printf("Digite um índice: ");
    scanf("%d", &pos);

    aluno = get_at(list, pos);
    if (aluno != NULL) 
        mostra_aluno(aluno, pos);
    else
        printf("Aluno não encontrado\n");

}

void pesquisar_por_matricula(List *list) {
    Aluno *aluno;
    char matricula[30];
    int index = 0;
    bool found = false;

    printf("Digite a matrícula: ");
    scanf("%s", matricula);

    while ((aluno = get_at(list, index)) != NULL) {
        if (strcmp(aluno->matricula, matricula) == 0) {
            mostra_aluno(aluno, index);
            found = true;
            break;
        }
        index++;
    }
    if (!found)
        printf("Não existe aluno com essa matrícula\n");
}

void pesquisar_por_nome(List *list) {
    Aluno *aluno;
    char nome[30];
    int index = 0;
    bool found = false;

    printf("Digite um nome: ");
    scanf("%s", nome);

    while ((aluno = get_at(list, index)) != NULL) {
        if (strcmp(aluno->nome, nome) == 0) {
            mostra_aluno(aluno, index);
            found = true;
            break;
        }
        index++;
    }
    if (!found)
        printf("Não existe aluno com essa matrícula\n");
}

void remover_por_posicao(List *list) {
    Aluno *aluno;
    int pos;

    mostrar_alunos(list);
    printf("\nDigite um dos índices listados acima: ");
    scanf("%d", &pos);

    aluno = remove_at(list, pos);

    if (aluno != NULL)
        printf("Removido com sucesso\n");
    else
        printf("Não foi possivel realizar a remoção\n");
}

void remover_por_matricula(List *list) {
    Aluno *aluno;
    char matricula[30];
    int index = 0;
    
    mostrar_alunos(list);
    printf("\nDigite a matrícula: ");
    scanf("%s", matricula);

    while ((aluno = get_at(list, index)) != NULL) {
        if (strcmp(aluno->matricula, matricula) == 0) {
            aluno = remove_at(list, index);
            if (aluno != NULL)
                printf("Removido com sucesso\n");
            else
                printf("Não foi possivel realizar a remoção\n");
            break;
        }
        index++;
    }
}

void remover_por_nome(List *list) {
    Aluno *aluno;
    char nome[30];
    int index = 0;

    mostrar_alunos(list);
    printf("Digite um nome: ");
    scanf("%s", nome);

    while ((aluno = get_at(list, index)) != NULL) {
        if (strcmp(aluno->nome, nome) == 0) {
            aluno = remove_at(list, index);
            if (aluno != NULL)
                printf("Removido com sucesso\n");
            else
                printf("Não foi possivel realizar a remoção\n");
            break;
        }
        index++;
    }
}

void remover_n_posicoes(List *list) {
    Aluno *aluno;
    int qt_posicoes;
    int index = 0;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &qt_posicoes);

    for (index = 0; index < qt_posicoes; index++) {
        aluno = pop_front(list);

        if (aluno == NULL)
            break;
    }

    if (index == 0)
        printf("Nenhum item foi removido\n");
    else 
        printf("Todos os %d primeiros items foram removidos.\n", qt_posicoes);
}

float media_aluno(Aluno *aluno) {
    float soma = 0;

    for (int i = 0; i < 3; i++) {
        soma += aluno->notas[i];
    }
    return soma / 3.0;
}

void copiar_lista_aprovados(List *list, List *list_aprovados) {
    Aluno *aluno;
    int index = 0;

    while ((aluno = get_at(list, index)) != NULL) {
        float media = media_aluno(aluno);
        
        if (media >= 6.0)
            push_back(list_aprovados, *aluno);
        index++;
    }
    printf("Operação finalizada!\n");
}

void copiar_lista_reprovados(List *list, List *list_reprovados) {
    Aluno *aluno;
    int index = 0;

    while ((aluno = get_at(list, index)) != NULL) {
        float media = media_aluno(aluno);
        
        if (media < 6.0)
            push_back(list_reprovados, *aluno);
        index++;
    }
    printf("Operação finalizada!\n");
}
