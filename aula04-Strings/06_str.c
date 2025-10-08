#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str);

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

  printf("Tamanho da string: %d\n", my_strlen(str));

  return 0;
}

int my_strlen(char *str){
  int i = 0;

  /*
   * Usando aritmética de ponteiros para...
   * ...percorrer a string até encontrar o '\0'
   */
  while(*(str + i) != '\0'){
    i++;
  }
  return i;
}