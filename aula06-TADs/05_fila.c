/*
 * Esse código simplificado para fins didático...
 * ... e em construção...
 * ... não deve ser utilizado!
 */

 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *front;  // começo da fila
  Node *rear;   // fim da fila
} Queue;

Queue *create_queue(void);
int enqueue(Queue **q, int value);
int dequeue(Queue **q, int *value);
void print_queue(Queue *q);
void free_queue(Queue **q);

int main(void) {
  Queue *q = create_queue();

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);

  print_queue(q);

  int value;
  if (dequeue(&q, &value))
    printf("Removed: %d\n", value);

  print_queue(q);

  free_queue(&q);

  return 0;
}

Queue *create_queue(void) {
  Queue *q = malloc(sizeof(Queue));

  if (!q)
    return NULL;

  q->front = NULL;
  q->rear = NULL;

  return q;
}

int enqueue(Queue **q, int value) {
  Node *new_node = malloc(sizeof(Node));

  if (!new_node)
    return 0;

  new_node->value = value;
  new_node->next = NULL;

  if ((*q)->rear == NULL) {
    (*q)->front = new_node;
    (*q)->rear = new_node;
    return 1;
  }

  (*q)->rear->next = new_node;
  (*q)->rear = new_node;

  return 1;
}

int dequeue(Queue **q, int *value) {
  if ((*q)->front == NULL)
    return 0;

  Node *temp = (*q)->front;
  *value = temp->value;

  (*q)->front = temp->next;
  if ((*q)->front == NULL)
    (*q)->rear = NULL;

  free(temp);

  return 1;
}

void print_queue(Queue *q) {
  Node *curr = q->front;

  printf("Queue: ");
  while (curr) {
    printf("%d ", curr->value);
    curr = curr->next;
  }

  printf("\n");
}

void free_queue(Queue **q) {
  Node *curr = (*q)->front;

  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }

  free(*q);
  *q = NULL;
}