#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "phase2.h"

stack *stack_new()
{
  stack *S = (stack *)calloc(1, sizeof(stack));
  Node *l = (Node *)calloc(1, sizeof(Node));
  S->top = l;
  S->floor = l;
  S->top->len = 0;
  return S;
}

void push(stack *S, char *x, int sum)
{
  Node *l = (Node *)calloc(1, sizeof(Node));
  l->data = x;
  l->sum = sum;
  l->next = S->top;
  l->len = S->top->len + 1;
  S->top = l;
}

// Pop top element from the stack
char *pop(stack *S)
{
  Node *temp;
  if (S->top == NULL)
  {
    return NULL;
  }

  temp = S->top;
  char *e = S->top->data;
  S->top = S->top->next;
  free(temp);
  return e;
}

void stack_print(stack *S)
{
  printf("TOP: \n");
  for (Node *l = S->top; l != S->floor; l = l->next)
  {
    printf("%s %d", l->data, l->sum);
    if (l->next != S->floor)
      printf(" | \n");
  }
}

int calc_avg(stack *S)
{
  int total_sum = 0;
  for (Node *l = S->top; l != S->floor; l = l->next)
  {
    total_sum += l->sum;
  }
  return total_sum / S->top->len;
}

int main()
{
  stack *S = stack_new();
  push(S, "a", 15);
  push(S, "b", 2);
  pop(S);
  push(S, "b", 13);
  int ans = calc_avg(S);
  printf("%d", ans);

  return 0;
}
