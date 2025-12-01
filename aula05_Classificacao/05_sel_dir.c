#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sel_dir(int *vector, size_t vector_size);
void print_vector(int *vector, size_t vector_size);

int main(){
  size_t vector_size = 10;

  // Alocando memória para o vetor
  int *int_pointer = malloc(sizeof(int)*vector_size);

  // verificando se a alocação foi bem sucedida
  if(int_pointer == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  // Lendo valores para o vetor
  srand(time(NULL));
  for(size_t i = 0; i < vector_size; i++){
    *(int_pointer + i) = rand() % 100;
  }

  // Vamos medir o tempo de execução
  clock_t start, end;
  start = clock();
  sel_dir(int_pointer, vector_size);
  end = clock();
  printf("\nTempo de execução: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void sel_dir(int *vector, size_t vector_size){
  size_t i, next_min_pos, min;
  int aux;

  // Ordenando o vetor
  for (i = 0; i < (vector_size-1); i++) {
     
    // Inicializando a posição do menor elemento
    min = i;

    // Encontrando a posição do menor elemento
    for (next_min_pos = (i+1); next_min_pos < vector_size; next_min_pos++){
      if(*(vector + next_min_pos) < *(vector + min)) 
        min = next_min_pos;
    }

    // Trocando os elementos
    if (i != min) {
      aux = *(vector + i);
      *(vector + i) = *(vector + min);
      *(vector + min) = aux;
    }
  }
}

void print_vector(int *vector, size_t vector_size){
  for(size_t i = 0; i < vector_size; i++){
    printf("%d ", *(vector + i));
  }
  printf("\n");
}
