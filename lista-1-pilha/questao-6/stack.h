#define MAX 100

typedef struct stack {
    int head;
    char values[MAX];
} Stack;


Stack *init_stack();
void push(Stack *stack, int value);
char pop(Stack *stack);
void empty_stack(Stack *stack);
int size_stack(Stack *stack);
int is_empty(Stack *stack);
int is_full(Stack *stack);
