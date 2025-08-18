/*
 * Em C, temos a passagem por valor como padrão...
 * ... ou seja, passamos uma cópia da variável (e seu valor) para a função
 */

 #include <stdio.h>

int func(int x) {
  x = x + 1;
  return x;
}

int main() {
  int a = 10;
  int result;

  printf("Valor da variavel a (antes): %d\n", a);
  result = func(a);
  printf("Valor da variavel a (depois): %d\n", a);

  printf("Valor do resultado: %d\n", result);

  return 0;
}