#define MAX 300

typedef struct contato {
    int numero_id;
    char nome[30];
    char sobrenome[30];
    char telefone[30];

} Contato;

typedef struct node {
    Contato contato;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
} List;


List *init_list();
Node *create_node();
int push_back(List *list, Contato contato);
int push_front(List *list, Contato contato);
int push_sorted(List *list, Contato contato);
int insert_at(List *list, int position, Contato contato);
Contato *pop_back(List *list);
Contato *pop_front(List *list);
Contato *remove_at(List *list, int position);
void empty_list(List *list);
int list_is_empty(List *list);
int size_list(List *list);
Contato *get_front(List *list);
Contato *get_back(List *list);
Contato *get_at(List *list, int position);
bool is_full(List *list);
bool is_sorted(List *list);
