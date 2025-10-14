#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(char *str);

int main(){

  char str[100];

  printf("Digite uma string: ");
  /*
   * Usando fgets para ler a string
   * ... pois scanf não lê strings com espaços
   */
  fgets(str, 100, stdin);
  // Remove o '\n' (enter), caso tenha...
  str[strcspn(str, "\n")] = '\0';

  printf("Tamanho da string: %zu\n", my_strlen(str));

  return 0;
}

size_t my_strlen(char *str){
  size_t i = 0;

  /*
   * Usando aritmética de ponteiros para...
   * ...percorrer a string até encontrar o '\0'
   */
  while(*(str + i) != '\0'){
    i++;
  }
  return i;
}