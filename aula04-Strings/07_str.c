#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverse_print(char *str, int size);

int main(){

  char *str_hello;
  
  // Alocando memória para a string
  str_hello = (char*) malloc(sizeof(char)*sizeof("Hello World!"));

  // Copiando a string para o array
  for(int i = 0; i < sizeof("Hello World!") - 1; i++){
    *(str_hello + i) = "Hello World!"[i];
  }

  // Adicionando o '\0' para indicar o fim da string
  str_hello[sizeof("Hello World!")] = '\0';

  // Chamando a função para imprimir a string invertida
  inverse_print(str_hello, strlen(str_hello));

  free(str_hello);

  return 0;
}

// Imprimindo a string invertida'
void inverse_print(char *str, int size) {

  // Agora vamos "brincar" de apontar

  /* 
   * Cuidado, str + size é o último caractere da string...
   * ... pois str já aponta para o primeiro caractere...
   * ... e strlen mostra o tamanho da string sem o '\0'
   */
  char *p_char = NULL;
  for(p_char = (str + size); p_char != str; p_char--){
      printf("%c", *p_char);
  }

  // Imprimindo primeiro caractere
  printf("%c\n", *p_char);
}