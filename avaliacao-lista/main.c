#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista_telefonica.h"


void inserir_contato(List *list);
void inserir_contato_ordenado(List *list);
void trocar_elementos(List *list);
void pesquisar_por_posicao(List *list);
void pesquisar_por_telefone(List *list);
void pesquisar_por_nome(List *list);
void remover_por_posicao(List *list);
void remover_por_telefone(List *list);
void remover_por_nome(List *list);
void remover_n_posicoes(List *list);
void copiar_contatos_por_ddds(List *list, List *list_ddds);
void esta_ordenada(List *list);
void mostrar_contatos(List *list);
void exportar_contatos_como_csv(List *list);

int main(void) {
    List *list = init_list();
    List *list_ddds = init_list();
    int opcao = 1;

    while (opcao) {
        printf(
            "Digite uma das Opções\n"
            "\t[1]  - Inserir contato\n"
            "\t[2]  - Inserir contato de forma ordenada\n"
            "\t[3]  - Consultar contato por posição\n"
            "\t[4]  - Consultar contato por telefone\n"
            "\t[5]  - Consultar contato por nome\n"
            "\t[6]  - Remover contato por posição\n"
            "\t[7]  - Remover contato por telefone\n"
            "\t[8]  - Remover contato por nome\n"
            "\t[9]  - Remover os N primeiros contatos\n"
            "\t[10] - Trocar a posição de dois contatos\n"
            "\t[11] - Copiar os contatos por um DDD específico\n"
            "\t[12] - Mostrar a lista de contatos selecionados por um DDD específico\n"
            "\t[13] - Mostrar todos os contatos\n"
            "\t[14] - Verificar se a lista está ordenada de forma crescente.\n"
            "\t[15] - Exportar contatos com CSV.\n"
            "\t[0]  - Sair\n"
            ">>> "
        );
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_contato(list);
                break;
            case 2:
                inserir_contato_ordenado(list);
                break;
            case 3:
                pesquisar_por_posicao(list);
                break;
            case 4:
                pesquisar_por_telefone(list);
                break;
            case 5:
                pesquisar_por_nome(list);
                break;
            case 6:
                remover_por_posicao(list);
                break;
            case 7:
                remover_por_telefone(list);
                break;
            case 8:
                remover_por_nome(list);
                break;
            case 9:
                remover_n_posicoes(list);
                break;
            case 10:
                trocar_elementos(list);
                break;
            case 11:
                copiar_contatos_por_ddds(list, list_ddds);
                break;
            case 12:
                mostrar_contatos(list_ddds);
                break;
            case 13:
                mostrar_contatos(list);
                break;
            case 14:
                esta_ordenada(list);
                break;
            case 15:
                exportar_contatos_como_csv(list);
                break;
        }
    }
    return 1;
}

int pega_proximo_id(List *list) {
    Contato *contato;
    int ultimo_id;

    contato = get_back(list);
    if (contato == NULL)
        return 0;
    ultimo_id = contato->numero_id;
    free(contato);
    return ultimo_id + 1;
}

void mostrar_contato(Contato *contato, int position) {
    printf("=================================\n");
    printf("índice = %d:\n", position);
    printf("\tNúmero ID: %d\n", contato->numero_id);
    printf("\tNome: %s\n", contato->nome);
    printf("\tSobrenome: %s\n", contato->sobrenome);
    printf("\tTelefone: %s\n", contato->telefone);
    printf("=================================\n");
    free(contato);
}

void mostrar_contatos(List *list) {
    Contato *contato;
    int index = 0;

    while ((contato = get_at(list, index)) != NULL) {
        mostrar_contato(contato, index);
        index++;
    }
    if(!index)
        printf("A lista está vazia!\n");
    else 
        printf("Operação finalizada!\n");
}

void entrada_dados_contato(Contato *contato) {
    printf("Digite o nome do contato: ");
    scanf("%s", contato->nome);

    printf("Digite o sobrenome do contato: ");
    scanf("%s", contato->sobrenome);

    printf("Digite o telefone do contato: ");
    scanf("%s", contato->telefone);
}

void inserir_contato(List *list) {
    Contato contato;

    contato.numero_id = pega_proximo_id(list);
    entrada_dados_contato(&contato);
    push_back(list, contato);
    printf("Operação finalizada!\n");
}

void inserir_contato_ordenado(List *list) {
    Contato contato;

    entrada_dados_contato(&contato);
    push_sorted(list, contato);
    printf("Operação finalizada!\n");
}

void trocar_elementos(List *list) {
    Contato *contato1, *contato2;
    int pos1, pos2;

    mostrar_contatos(list);
    printf("\nDigite um dos índices listados acima: ");
    scanf("%d", &pos1);

    printf("Digite um dos índices listados acima: ");
    scanf("%d", &pos2);
    
    contato1 = get_at(list, pos1);
    contato2 = get_at(list, pos2);

    if (contato1 != NULL && contato2 != NULL) {
        remove_at(list, pos1);
        insert_at(list, pos1, *contato2);

        remove_at(list, pos2);
        insert_at(list, pos2, *contato1);
        printf("Operação finalizada!\n");
    }
    else
        printf("Não foi prossivel fazer a troca\n");
    
    free(contato1);
    free(contato2);
}

void pesquisar_por_posicao(List *list) {
    Contato *contato;
    int pos;

    printf("Digite um índice: ");
    scanf("%d", &pos);

    contato = get_at(list, pos);
    if (contato != NULL) 
        mostrar_contato(contato, pos);
    else
        printf("Contato não encontrado\n");
}

void pesquisar_por_telefone(List *list) {
    Contato *contato;
    char telefone[30];
    int index = 0;
    bool found = false;

    printf("Digite um telefone: ");
    scanf("%s", telefone);

    while ((contato = get_at(list, index)) != NULL) {
        if (strcmp(contato->telefone, telefone) == 0) {
            mostrar_contato(contato, index);
            found = true;
            break;
        }
        free(contato);
        index++;
    }
    if (!found)
        printf("Não existe contato com esse telefone\n");
}

void pesquisar_por_nome(List *list) {
    Contato *contato;
    char nome[30];
    int index = 0;
    bool found = false;

    printf("Digite um nome: ");
    scanf("%s", nome);

    while ((contato = get_at(list, index)) != NULL) {
        if (strcmp(contato->nome, nome) == 0) {
            mostrar_contato(contato, index);
            found = true;
            break;
        }
        free(contato);
        index++;
    }
    if (!found)
        printf("Não existe contato com esse nome\n");
}

void remover_por_posicao(List *list) {
    Contato *contato;
    int pos;

    mostrar_contatos(list);
    printf("\nDigite um dos índices listados acima: ");
    scanf("%d", &pos);

    contato = remove_at(list, pos);

    if (contato != NULL)
        printf("Removido com sucesso\n");
    else
        printf("Não foi possivel realizar a remoção\n");
    free(contato);
}

void remover_por_telefone(List *list) {
    Contato *contato;
    char telefone[30];
    int index = 0;
    
    mostrar_contatos(list);
    printf("\nDigite um telefone: ");
    scanf("%s", telefone);

    while ((contato = get_at(list, index)) != NULL) {
        if (strcmp(contato->telefone, telefone) == 0) {
            contato = remove_at(list, index);
            if (contato != NULL)
                printf("Removido com sucesso\n");
            else
                printf("Não foi possivel realizar a remoção\n");
            break;
            free(contato);
        }
        free(contato);
        index++;
    }
}

void remover_por_nome(List *list) {
    Contato *contato;
    char nome[30];
    int index = 0;

    mostrar_contatos(list);
    printf("Digite um nome: ");
    scanf("%s", nome);

    while ((contato = get_at(list, index)) != NULL) {
        if (strcmp(contato->nome, nome) == 0) {
            contato = remove_at(list, index);
            if (contato != NULL)
                printf("Removido com sucesso\n");
            else
                printf("Não foi possivel realizar a remoção\n");
            break;
            free(contato);
        }
        free(contato);
        index++;
    }
}

void remover_n_posicoes(List *list) {
    Contato *contato;
    int qt_posicoes;
    int index = 0;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &qt_posicoes);

    for (index = 0; index < qt_posicoes; index++) {
        contato = pop_front(list);

        if (contato == NULL)
            break;
        free(contato);
    }

    if (index == 0)
        printf("Nenhum contato foi removido\n");
    else 
        printf("Todos os %d primeiros contatos foram removidos.\n", qt_posicoes);
}

void copiar_contatos_por_ddds(List *list, List *list_ddds) {
    Contato *contato;
    int index = 0;
    char ddd[2];

    printf("Digite um DDD (Ex: 75): ");
    scanf("%s", ddd);

    while ((contato = get_at(list, index)) != NULL) {
        if ((strncmp(ddd, contato->telefone, 2)) == 0)
            push_back(list_ddds, *contato);
        free(contato);
        index++;
    }
    printf("Operação finalizada!\n");
}

void esta_ordenada(List *list) {
    bool sorted = is_sorted(list);

    if (sorted)
        printf("A lista está ordenada de forma crescente.\n");
    else
        printf("A lista não está ordenada de forma crescente.\n");
}

void exportar_contatos_como_csv(List *list) {
    FILE *fpt;
    Contato *contato;
    int index = 0;

    fpt = fopen("contatos.csv", "w+");
    if (fpt == NULL) {
        perror("Não foi possivel exportar o arquivo: ");
        return;
    }

    fprintf(fpt,
        "numero_id;nome;sobrenome;telefone;\n"
    );

    while ((contato = get_at(list, index)) != NULL) {
         fprintf(fpt, 
            "%d;%s;%s;%s\n",
            contato->numero_id, contato->nome, contato->sobrenome, contato->telefone
        );
        fflush(fpt);
        
        index++;
    }
    fclose(fpt);
    printf("O arquivo foi exportado com sucesso.\n");
}
