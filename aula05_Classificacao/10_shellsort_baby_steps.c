#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void shellsort(int *vector, size_t vector_size);
void shellsort_incr(int *vector, size_t inicio, size_t incr, size_t vector_size);
void print_vector(int *vector, size_t vector_size);

int main(){
  system("clear");
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

  printf("Vetor original: \n");
  print_vector(int_pointer, vector_size);

  // Ordenando o vetor
  shellsort(int_pointer, vector_size);

  printf("Vetor ordenado: \n");
  print_vector(int_pointer, vector_size);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void shellsort(int *vector, size_t vector_size){
  char ch;
  
  printf("Vamos ordenar passo a passo!");
  ch = getchar();

  // Para cada incremento
  for (size_t i = vector_size/2; i > 2; i /= 2){
    
    // Ordena cada sublista
    for (size_t j = 0; j < i; j++)
      shellsort_incr(vector, j, i, vector_size);
  }

  // Ordena a lista final
  shellsort_incr(vector, 0, 1, vector_size);
}

void shellsort_incr(int *vector, size_t inicio, size_t incr, size_t vector_size) {
  int aux;
  bool troca = false;
  char ch;
  
  for (size_t i = inicio+incr; i < vector_size; i += incr){
    system("clear");
    print_vector(vector, vector_size);
    printf("\nCompara as posições %zu e %zu!", i-incr, i);
    ch = getchar();
    troca = false;

    for (size_t j = i; ((j >= incr) && (*(vector + j) < *(vector + j-incr))); j -= incr){
      printf("Troca as posições %zu e %zu!\n\n", j-incr, j);

      troca = true;
      aux = *(vector + j);
      *(vector + j) = *(vector + j-incr);
      *(vector + j-incr) = aux;

      print_vector(vector, vector_size);
      ch = getchar();
    }

    if(!troca){
      printf("Não realiza troca! [posições ordenadas]\n");
      ch = getchar();
    }
  }
}

void print_vector(int *vector, size_t vector_size){
  printf("Posição: ");
  for(size_t i = 0; i < vector_size; i++){
    printf("%3zu", i);
  }
  printf("\nValores: ");
  for(size_t i = 0; i < vector_size; i++){
    printf("%3d", *(vector + i));
  }
  printf("\n");
}