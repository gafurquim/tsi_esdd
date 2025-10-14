#include <stdio.h>
#include <stdlib.h> // para o uso de malloc

int main(){
  int *int_pointer = NULL;

  printf("Endereço do ponteiro (NULL): %p\n", int_pointer);
  // Alocando memória para um int
  int_pointer = (int*) malloc(sizeof(int));
  // verificando se a alocação foi bem sucedida
  if(int_pointer == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  *int_pointer = 10;

  printf("Endereço do ponteiro: %p\n", int_pointer);
  printf("Valor do ponteiro: %d\n", *int_pointer);

  // Desalocando memória
  free(int_pointer);

  return 0;
}