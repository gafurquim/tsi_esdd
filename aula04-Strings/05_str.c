#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  /* 
   * Por estar entre aspas duplas, é uma string... 
   * ...ou seja, 'sizeof' conta o '\0' na tamanho
   */
  printf("Tamanho da string (sizeof): %d\n", sizeof("Hello World!"));
  // ...mas cuidado, 'strlen' não conta o '\0'
  printf("Tamanho da string (strlen): %d\n", strlen("Hello World!"));

  char *str_hello = NULL;
  // strlen precisaria somar 1 para considerar o '\0'
  str_hello = (char*) malloc(sizeof(char)*sizeof("Hello World!"));
  printf("Tamanho da string após allocação: %d\n", strlen(str_hello));

  /*
   * Lembrando, sizeof conta o '\0'...
   * ...e "Hello World!" é uma string...
   * ...ou seja, ela já tem o '\0' no final [13]
  */
  for(int i = 0; i < sizeof("Hello World!"); i++){
    str_hello[i] = "Hello World!"[i];
  }

  printf("sizeof só mostra o tamanho do ponteiro: %d\n", sizeof(str_hello));
  printf("Mas strlen mostra o tamanho da string: %d\n", strlen(str_hello));

  printf("%s\n", str_hello);

  // Liberando o espaço alocado em memória
  free(str_hello);

  return 0;
}