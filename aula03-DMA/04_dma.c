#include <stdio.h>
#include <stdlib.h>

int main(){
  int size = 100;
  int *int_pointer = NULL;

  // Alocando memória para um array de int
  int_pointer = (int*) malloc(size*sizeof(int));
  // verificando se a alocação foi bem sucedida
  if(int_pointer == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  for(int i = 0; i < size; i++){
    int_pointer[i] = i;
  }

  for(int i = 0; i < size; i++){
    printf("%d\n", int_pointer[i]);
  }

  free(int_pointer);

  return 0;
}