/*
 * Implementação de um algoritmo de ordenação quick sort
 * 
 * Essa é outro algoritmo de classificação por trocas
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *values, int begin, int end);
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

  printf("Vetor original: ");
  print_vector(int_pointer, vector_size);

  // Ordenando o vetor
  quicksort(int_pointer, 0, vector_size-1);

  printf("Vetor ordenado: ");
  print_vector(int_pointer, vector_size);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void quicksort(int *values, int begin, int end) {
    if (begin >= end - 1) return; // Caso base: array de 1 ou 0 elementos já está ordenado

    int i = begin, j = end - 1;
    int pivo = *(values + begin + (end - begin) / 2);
    int aux;

    while (i <= j)
    {
        while (i < end && *(values + i) < pivo)
            i++;
        while (j >= begin &&  *(values + j) > pivo)
            j--;

        if (i <= j)
        {
            aux = *(values + i);
            *(values + i) = *(values + j);
            *(values + j) = aux;
            i++;
            j--;
        }
    }

    if (begin < j)
        quicksort(values, begin, j + 1);
    if (i < end)
        quicksort(values, i, end);
}

void print_vector(int *vector, size_t vector_size){
  for(size_t i = 0; i < vector_size; i++){
    printf("%d ", *(vector + i));
  }
  printf("\n");
}