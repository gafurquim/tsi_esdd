#include <stdio.h>

void swap(int *valor_1, int *valor_2);

int main() {
  int a, b;

  printf("Digite o valor de a: ");
  scanf("%d", &a);

  printf("Digite o valor de b: ");
  scanf("%d", &b);

  printf("\nValor da variavel a: %d\n", a);
  printf("Valor da variavel b: %d\n", b);

  swap(&a, &b);
  printf("--------------------------------\n");
  
  printf("Valor da variavel a (depois): %d\n", a);
  printf("Valor da variavel b (depois): %d\n", b);

  return 0;
}

void swap(int *valor_1, int *valor_2) {
  int valor_aux;

  valor_aux = *valor_1;
  *valor_1 = *valor_2;
  *valor_2 = valor_aux;
}