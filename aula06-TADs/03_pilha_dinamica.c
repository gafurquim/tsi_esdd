#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void push(Node **top, int value);
int pop(Node **top, int *value); 
void print_stack(Node *top);
void free_stack(Node **top);

int main() {
  Node *stack = NULL;
  int value;

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  print_stack(stack);

  if (pop(&stack, &value))
    printf("Popped: %d\n", value);

  print_stack(stack);

  free_stack(&stack);
  return 0;
}

void push(Node **top, int value) {
  Node *new_node = malloc(sizeof(Node));

  if (!new_node)
    return;

  new_node->value = value;
  new_node->next = *top;
  *top = new_node;
}

int pop(Node **top, int *value) {
  if (*top == NULL)
    return 0; // pilha vazia

  Node *temp = *top;
  *value = temp->value;
  *top = temp->next;
  free(temp);

  return 1;
}

void print_stack(Node *top) {
  printf("Stack: ");
  for (; top != NULL; top = top->next)
    printf("%d ", top->value);
  printf("\n");
}

void free_stack(Node **top) {
  Node *curr = *top;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }
  *top = NULL;
}
