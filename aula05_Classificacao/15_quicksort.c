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
void swap(int *values, int i, int j);
void print_vector(int *vector, size_t vector_size);
int findpivot(int i, int j);
int partition(int *values, int left, int right, int pivot);

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
  int pivotindex = findpivot(begin, end);
  swap(values, pivotindex, end); // coloca o pivô no final
  // k será a primeira posição no subarray direito
  int k = partition(values, begin, end-1,values[end]);
  swap(values, k, end);                       // coloca o pivô em seu lugar
  if ((k-begin) > 1) quicksort(values, begin, k-1); // Ordena a partição esquerda
  if ((end-k) > 1) quicksort(values, k+1, end); // Ordena a partição direita
}

int findpivot(int i, int j) {
  return (i+j)/2;
}

int partition(int *values, int left, int right, int pivot) {
  while (left <= right) { // Move os limites até que se encontrem
    while (*(values + left) < pivot) left++;
    while ((right >= left)  && (*(values + right) >= pivot)) right--;
    if (right > left) swap(values, left, right);  // troca valores fora do lugar
   }
  return left; // Retorna primeira posição no subarray direito
}

void swap(int *values, int i, int j) {
  int aux = *(values + i);
  *(values + i) = *(values + j);
  *(values + j) = aux;
}

void print_vector(int *vector, size_t vector_size){
  for(size_t i = 0; i < vector_size; i++){
    printf("%d ", *(vector + i));
  }
  printf("\n");
}