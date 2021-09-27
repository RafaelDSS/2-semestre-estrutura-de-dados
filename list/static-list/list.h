#define MAX 100

typedef struct list {
    int values[MAX];
    int size;
} List;

List *init_list();
int push_back(List *list, int number);
int push_front(List *list, int number);
int push_sorted(List *list, int number);
int insert_at(List *list, int position, int number);
int pop_back(List *list);
int pop_front(List *list);
int remove_at(List *list, int position);
void empty_list(List *list);
int size_list(List *list);
int list_is_empty(List *list);
int list_is_full(List *list);