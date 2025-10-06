#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str){
  int i = 0;

  /*
   * Usando aritmética de ponteiros para percorrer a string...
   * ... até encontrar o '\0'
   */
  while(*(str + i) != '\0'){
    i++;
  }
  return i;
}

int main(){

  char str_hello[100];

  printf("Digite uma string: ");
  /*
   * Usando fgets para ler a string
   * ... pois scanf não lê strings com espaços
   */
  fgets(str_hello, 100, stdin);

  printf("Tamanho da string: %d\n", my_strlen(str_hello));

  return 0;
}