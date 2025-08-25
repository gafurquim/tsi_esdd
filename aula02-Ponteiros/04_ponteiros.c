/*
 * Código copiado de:
 * https://github.com/ednilsonrossi/sin-esdd-2023/blob/main/aula4-ponteiros/Exemplo6.c
 * Obrigado pelo material Ednilson, deram várias ideias... :)
 */

#include <stdio.h>

void cuboPorValor(int n);
void cuboPorReferencia(int *n);

int main(int argc, char const *argv[]){
  int value = 5;

  cuboPorValor(value);
  printf("Valor: %d\n", value);

  cuboPorReferencia(&value);
  printf("Valor: %d\n", value);

  return 0;
}

void cuboPorValor(int n){
  n = n * n * n;
}
void cuboPorReferencia(int *n){
  *n = (*n) * (*n) * (*n);
}