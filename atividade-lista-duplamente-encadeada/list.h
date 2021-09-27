typedef struct aluno {
    char nome[30];
    char matricula[30];
    float notas[3];
} Aluno;

typedef struct node {
    Aluno aluno;
    struct node *next;
    struct node *previous;
} Node;

typedef struct list {
    Node *head;
} List;


List *init_list();
Node *create_node();
int push_back(List *list, Aluno aluno);
int push_front(List *list, Aluno aluno);
int push_sorted(List *list, Aluno aluno);
int insert_at(List *list, int position, Aluno aluno);
Aluno *pop_back(List *list);
Aluno *pop_front(List *list);
Aluno *remove_at(List *list, int position);
void empty_list(List *list);
int list_is_empty(List *list);
int size_list(List *list);
Aluno *get_front(List *list);
Aluno *get_back(List *list);
Aluno *get_at(List *list, int position);
