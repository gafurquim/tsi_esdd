#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *base;        // Ponteiro base para a fila
  size_t size;      // Capacidade da fila
  size_t front;     // Indice do primeiro elemento
  size_t rear;      // Indice do proximo elemento a ser inserido
  size_t count;     // Numero de elementos na fila
} Queue;

// Criar fila dinamicamente
Queue *create_queue(size_t queue_size);
// Destroi a fila
void destroy_queue(Queue *q);
// Adicionar elemento na fila
int enqueue(Queue *q, int value);
// Remover elemento da fila
int dequeue(Queue *q, int *value);
// Mostrar conteudo da fila
void print_queue(Queue *q);

int main(void) {
  size_t queue_size = 5;
  Queue *fila = create_queue(queue_size);

  char opcao;
  int valor;

  do {
    printf("\n=== MENU DA FILA ===\n");
    printf("i - Inserir na fila\n");
    printf("r - Remover da fila\n");
    printf("p - Mostrar fila\n");
    printf("s - Sair\n");
    printf("Escolha uma opcao: ");
    scanf(" %c", &opcao);  // espaço antes do %c ignora '\n'

    switch (opcao) {
      case 'i':
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &valor);
        if (enqueue(fila, valor) == 0)
          printf("Valor %d inserido com sucesso!\n", valor);
        else
          printf("Fila cheia!\n");
        break;

      case 'r':
        if (dequeue(fila, &valor) == 0)
          printf("Removido: %d\n", valor);
        else
          printf("Fila vazia!\n");
        break;

      case 'p':
        print_queue(fila);
        break;

      case 's':
        printf("Encerrando programa...\n");
        break;

      default:
        printf("Opcao invalida!\n");
    }

  } while (opcao != 's');

  destroy_queue(fila);
  return 0;
}

Queue *create_queue(size_t queue_size) {
  Queue *q = malloc(sizeof(Queue));
  if (q == NULL) return NULL;

  q->base = malloc(sizeof(int) * queue_size);
  if (q->base == NULL) {
    free(q);
    return NULL;
  }

  q->size = queue_size;
  q->front = 0;
  q->rear = 0;
  q->count = 0;

  return q;
}

void destroy_queue(Queue *q) {
  if (q) {
    free(q->base);
    free(q);
  }
}

int enqueue(Queue *q, int value) {
  if (q->count == q->size)
    return 1; // Fila cheia

  *(q->base + q->rear) = value;
  q->rear = (q->rear + 1) % q->size;
  q->count++;
  return 0;
}

int dequeue(Queue *q, int *value) {
  if (q->count == 0)
    return 1; // Fila vazia

  *value = *(q->base + q->front);
  q->front = (q->front + 1) % q->size;
  q->count--;
  return 0;
}

void print_queue(Queue *q) {
  if (q->count == 0) {
    printf("Fila vazia!\n");
    return;
  }

  printf("Fila: ");
  for (size_t i = 0; i < q->count; i++) {
    size_t index = (q->front + i) % q->size;
    printf("%d ", *(q->base + index));
  }
  printf("\n");
}