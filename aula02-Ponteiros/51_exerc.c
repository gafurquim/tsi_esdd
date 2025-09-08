#include <stdio.h>

void swap(/* implementar */);

int main() {
  int a;
  int b;

  printf("Digite o valor de a: ");
  scanf("%d", &a);

  printf("Digite o valor de b: ");
  scanf("%d", &b);

  printf("\nValor da variavel a: %d\n", a);
  printf("Valor da variavel b: %d\n", b);

  swap(/* implementar */);
  printf("--------------------------------\n");
  
  printf("Valor da variavel a (depois): %d\n", a);
  printf("Valor da variavel b (depois): %d\n", b);

  return 0;
}

void swap(/* implementar */) {
  // implementar
}