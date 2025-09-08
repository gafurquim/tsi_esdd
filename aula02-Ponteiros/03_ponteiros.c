#include <stdio.h>

void printValue(int *p);

int main() {
  int a = 10;

  printf("Valor da variavel a: %d\n", a);
  printf("Endereco da variavel a: %p\n", &a);

  printValue(&a);
  printf("Valor da variavel a (depois): %d\n", a);

  return 0;
}

void printValue(int *p) {
  printf("----------------------------------\n");
  (*p)++;
  printf("Valor do parametro: %d\n", *p);
  printf("O endereço do parametro: %p\n", p);
}