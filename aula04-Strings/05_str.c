#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  // Por estar entre aspas duplas, é uma string... 
  // ...ou seja, 'sizeof' conta o '\0' na tamanho
  printf("Tamanho da string (sizeof): %d\n", sizeof("Hello World!"));
  // ...mas cuidado, 'strlen' não conta o '\0'
  printf("Tamanho da string (strlen): %d\n", strlen("Hello World!"));

  char *str_hello;
  // strlen precisaria somar 1 para considerar o '\0'
  str_hello = (char*) malloc(sizeof(char)*sizeof("Hello World!"));
  printf("Tamanho da string após allocação: %d\n", strlen(str_hello));

  for(int i = 0; i < strlen("Hello World!"); i++){
    str_hello[i] = "Hello World!"[i];
  }

  // Adicionando o '\0' para indicar o fim da string
  str_hello[sizeof("Hello World!")] = '\0';

  printf("sizeof só mostra o tamanho do ponteiro: %d\n", sizeof(str_hello));
  printf("Mas strlen mostra o tamanho da string: %d\n", strlen(str_hello));

  printf("%s\n", str_hello);

  free(str_hello);

  return 0;
}