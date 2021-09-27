typedef struct node {
    int number;
    struct node *previous;
} Node;

typedef struct stack {
    Node *head;
} Stack;

Node *init_stack(void);
void push(Stack *stack, int number);
int pop(Stack *stack);
void empty_stack(Stack *stack);
int size_stack(Stack *stack);
int is_empty(Stack *stack);
Node *create_node();