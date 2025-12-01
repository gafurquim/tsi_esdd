#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *base;     // ponteiro para a base da pilha
  int *top;      // ponteiro para o topo (proxima posicao livre)
  size_t size;   // capacidade total da pilha
} Stack;

// Criar pilha com tamanho dado
Stack *create_stack(size_t stack_size);
// Empurrar valor na pilha
int push(Stack *s, int value);
// Remover valor da pilha
int pop(Stack *s, int *out_value);
// Liberar memória
void destroy_stack(Stack *s);
// Mostrar conteudo da pilha (para depuracao)
void print_stack(Stack *s);


int main(void) {
  size_t stack_size = 5;
  Stack *pilha = create_stack(stack_size);

  int ret = push(pilha, 10);
  if(ret == 0)
    printf("10 inserido com sucesso\n");
  else
    printf("Stack overflow!\n");
  ret = push(pilha, 20);
  if(ret == 0)
    printf("20 inserido com sucesso\n");
  else
    printf("Stack overflow!\n");
  ret = push(pilha, 30);
  if(ret == 0)
    printf("30 inserido com sucesso\n");
  else
    printf("Stack overflow!\n");

  print_stack(pilha);

  int value;
  if (pop(pilha, &value) == 0)
    printf("Removido: %d\n", value);
  else
    printf("Stack underflow!\n");

  print_stack(pilha);

  destroy_stack(pilha);
  return 0;
}

Stack *create_stack(size_t stack_size) {
  Stack *s = malloc(sizeof(Stack));

  if (!s) {
    perror("Erro na alocação de memória\n");
    exit(EXIT_FAILURE);
  }

  s->base = malloc(sizeof(int) * stack_size);
  if (!s->base) {
    perror("Erro na alocação de memória\n");
    free(s);
    exit(EXIT_FAILURE);
  }

  s->top = s->base;     // pilha inicialmente vazia
  s->size = stack_size;

  return s;
}

int push(Stack *s, int value) {
  if ((size_t)(s->top - s->base) >= s->size) {
    // Stack overflow!
    return 1;
  }

  *(s->top) = value;  // escrever no topo atual
  s->top++;           // mover para a proxima posicao livre
  return 0;
}

int pop(Stack *s, int *out_value) {
  if (s->top == s->base) {
    // Stack underflow!
    return 1;
  }

  s->top--;               // voltar uma posicao
  *out_value = *(s->top); // obter o valor do topo
  return 0;
}

void destroy_stack(Stack *s) {
  free(s->base);
  free(s);
}

void print_stack(Stack *s) {
  printf("Conteúdo da pilha:\n");
  for (int *p = s->top-1; p >= s->base; p--) {
    printf("%d\n", *p);
  }
  printf("\n");
}
