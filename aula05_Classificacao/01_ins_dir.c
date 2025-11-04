/*
 * Implementação de um algoritmo de ordenação por inserção direta
 * 
 * Essa tipo de algoritmo (classificação por inserção) é um dos mais simples
 * e realiza a ordenação inserindo os elementos em uma nova posição correta.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercao_direta(int *vector, size_t vector_size);
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
  insercao_direta(int_pointer, vector_size);

  printf("Vetor ordenado: ");
  print_vector(int_pointer, vector_size);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void insercao_direta(int *vector, size_t vector_size){
  size_t i = 1, pos_menor;
  int aux;

  while (i < vector_size){
    // Encontrando a posição do menor elemento
    pos_menor = i;

    // Deslocando o menor elemento para a posição correta
    while (pos_menor > 0 && *(vector + pos_menor-1) > *(vector + pos_menor)){
      aux = *(vector + pos_menor);
      *(vector + pos_menor) = *(vector + pos_menor-1);
      *(vector + pos_menor-1) = aux;
      pos_menor--;
    }
    i++;
  }
}

void print_vector(int *vector, size_t vector_size){
  for(size_t i = 0; i < vector_size; i++){
    printf("%d ", *(vector + i));
  }
  printf("\n");
}
