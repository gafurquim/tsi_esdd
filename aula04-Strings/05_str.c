#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  /* 
   * Por estar entre aspas duplas, é uma string... 
   * ...ou seja, 'sizeof' conta o '\0' na tamanho
   */
  printf("Tamanho da string (sizeof): %zu\n", sizeof("Hello World!"));
  // ...mas cuidado, 'strlen' não conta o '\0'
  printf("Tamanho da string (strlen): %zu\n", strlen("Hello World!"));

  char *str_hello = NULL;
  // strlen precisaria somar 1 para considerar o '\0'
  str_hello = (char*) malloc(sizeof(char)*sizeof("Hello World!"));
  // verificando se a alocação foi bem sucedida
  if(str_hello == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  printf("Tamanho da string após allocação: %zu\n", strlen(str_hello));

  /*
   * Lembrando, sizeof conta o '\0'...
   * ...e "Hello World!" é uma string...
   * ...ou seja, ela já tem o '\0' no final [13]
  */
  for(size_t i = 0; i < sizeof("Hello World!"); i++){
    str_hello[i] = "Hello World!"[i];
  }

  printf("sizeof só mostra o tamanho do ponteiro: %zu\n", sizeof(str_hello));
  printf("Mas strlen mostra o tamanho da string: %zu\n", strlen(str_hello));

  printf("%s\n", str_hello);

  // Liberando o espaço alocado em memória
  free(str_hello);

  return 0;
}