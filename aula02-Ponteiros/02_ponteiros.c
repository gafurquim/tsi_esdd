#include <stdio.h>

void printValue(int p) {
  printf("----------------------------------\n");
  printf("Valor do parametro: %d\n", p);
  printf("O endereço do parametro: %p\n", &p);
}

int main() {
  int a = 10;

  printf("Valor da variavel a: %d\n", a);
  printf("Endereco da variavel a: %p\n", &a);

  printValue(a);

  return 0;
}