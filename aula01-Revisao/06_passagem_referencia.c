/*
 * Ponteiros permitem a passagem por referência...
 * ... pois manipulamos a variável em memória (seu valor) utilizando o seu endereço
 */

 #include <stdio.h>

int func(int *x) {
  // Aqui temos um "detalhe" importante...
  // ... precisamos do "*" para acessar o valor da variável
  *x = *x + 1;
  return *x;
}

int main() {
  int a = 10;
  int result;


  printf("Valor da variavel a (antes): %d\n", a);
  result = func(&a);
  printf("Valor da variavel a (depois): %d\n", a);

  printf("Valor do resultado: %d\n", result);

  return 0;
}