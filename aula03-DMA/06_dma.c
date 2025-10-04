#include <stdio.h>
#include <stdlib.h>

void fillArray(int array[], int size);

int main(){
  int *int_pointer = NULL;
  int size;

  printf("Digite o tamanho do array: ");
  scanf("%d", &size);

  // Alocando memória para "size" inteiros
  int_pointer = (int*) malloc(sizeof(int)*size);

  if(int_pointer == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  fillArray(int_pointer, size);

  for(int i = 0; i < size; i++){
    printf("%d\n", int_pointer[i]);
  }

  // Desalocando memória
  free(int_pointer);

  return 0;
}

void fillArray(int array[], int size){
  for(int i = 0; i < size; i++){
    // i[array] = i; == *(i + array);
    array[i] = i; // == *(array + i);
  }
}

// Exercício:
// Modificar para utilização de aritmética de ponteiros...
// ...ao invés de índices.