typedef struct list_node Node;
struct list_node {
  char* data;
  int len;
  int sum;
  Node* next;
};

typedef struct stack_header stack;
struct stack_header {
  Node* top;
  Node* floor;
};

stack* stack_new();
void push(stack* S, char* x, int sum);
char* pop(stack* S);
void stack_print(stack* S);
int calc_avg(stack* S);

