#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_to_middle(char *str);

int main(){

  char *str_pointer;
  
  // Alocando memória para a string
  str_pointer = (char*) malloc(sizeof(char)*100);
  // verificando se a alocação foi bem sucedida
  if(str_pointer == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  // Lendo uma string qualquer
  printf("Digite uma frase: ");
  fgets(str_pointer, 100, stdin);
  str_pointer[strcspn(str_pointer, "\n")] = '\0';

  // Chamando a função para imprimir a string invertida
  print_to_middle(str_pointer);

  free(str_pointer);

  return 0;
}

void print_to_middle(char *str){

  // Esse vai apontar para a primeira posição da string
  char *p_first_char = str;

  // Esse vai apontar para a última posição da string...
  // ... desconsiderando o '\0'
  char *p_last_char = (str + strlen(str) - 1);

  /* 
  * Agora vai fazer os dois se juntarem no meio...
  * ... perceba que um ponteiro incrementa e o outro decrementa
  * OBS: nunca faça essas operações com o ponteiro inicial (str no caso)
  * ... senão você pode perder a posição inicial da string
  */
  for(; p_first_char <= p_last_char; p_first_char++, p_last_char--){
      printf("%c | %c\n", *p_first_char, *p_last_char);
  }
}