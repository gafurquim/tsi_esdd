#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverse_print(char *str);

int main(){

  char *str_hello_pointer;
  
  // Alocando memória para a string
  str_hello_pointer = (char*) malloc(sizeof(char)*sizeof("Hello World!"));

  // Copiando a string para o array
  for(int i = 0; i < sizeof("Hello World!"); i++){
    *(str_hello_pointer + i) = "Hello World!"[i];
  }

  // Chamando a função para imprimir a string invertida
  inverse_print(str_hello_pointer);

  free(str_hello_pointer);

  return 0;
}

// Imprimindo a string invertida'
void inverse_print(char *str) {

  // Agora vamos "brincar" de apontar

  /* 
   * Cuidado, str + strlen(str) é o último caractere da string...
   * ... pois str já aponta para o primeiro caractere...
   * ... e strlen mostra o tamanho da string sem o '\0'
   */
  char *p_char = NULL;
  for(p_char = (str + strlen(str) - 1); p_char != str; p_char--){
      printf("%c", *p_char);
  }

  /* 
  * OBS: nunca faça operações com o ponteiro inicial (str no caso)
  * ... senão você pode perder a posição inicial da string
  */

  // Imprimindo primeiro caractere
  printf("%c\n", *p_char);
}