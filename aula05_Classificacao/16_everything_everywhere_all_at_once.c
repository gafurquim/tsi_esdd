#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercao_direta(int *vector, size_t vector_size);
void sel_dir(int *vector, size_t vector_size);
void shellsort(int *vector, size_t vector_size);
void shellsort_incr(int *vector, size_t inicio, size_t incr, size_t vector_size);
void merge_sort(int *vetor, int comeco, int fim);
void merge(int *vetor, int comeco, int meio, int fim);
void quicksort(int *values, int begin, int end);
void swap(int *values, int i, int j);
int findpivot(int i, int j);
int partition(int *values, int left, int right, int pivot);

int main(){
  size_t vector_size = 5;

  // Alocando memória para o vetor
  int *int_pointer = malloc(sizeof(int)*vector_size);
  int *int_pointer_aux = malloc(sizeof(int)*vector_size);

  // verificando se a alocação foi bem sucedida
  if(int_pointer == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  // Lendo valores para o vetor
  srand(time(NULL));
  for(size_t i = 0; i < vector_size; i++){
    *(int_pointer + i) = rand() % 10;
    *(int_pointer_aux + i) = *(int_pointer + i);
  }

  // Vamos medir o tempo de execução
  clock_t start, end;
  start = clock();
  insercao_direta(int_pointer, vector_size);
  end = clock();
  printf("\nTempo de execução (Inserção Direta): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  for(size_t i = 0; i < vector_size; i++){
    *(int_pointer + i) = *(int_pointer_aux + i);
  }

  // Vamos medir o tempo de execução
  start = clock();
  sel_dir(int_pointer, vector_size);
  end = clock();
  printf("\nTempo de execução (Seleção Direta): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  for(size_t i = 0; i < vector_size; i++){
    *(int_pointer + i) = *(int_pointer_aux + i);
  }

  // Vamos medir o tempo de execução
  start = clock();
  shellsort(int_pointer, vector_size);
  end = clock();
  printf("\nTempo de execução (ShellSort): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  for(size_t i = 0; i < vector_size; i++){
    *(int_pointer + i) = *(int_pointer_aux + i);
  }

  // Vamos medir o tempo de execução
  start = clock();
  merge_sort(int_pointer, 0, vector_size-1);
  end = clock();
  printf("\nTempo de execução (MergeSort): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  for(size_t i = 0; i < vector_size; i++){
    *(int_pointer + i) = *(int_pointer_aux + i);
  }

  // Vamos medir o tempo de execução
  start = clock();
  quicksort(int_pointer, 0, vector_size-1);
  end = clock();
  printf("\nTempo de execução (Quicksort): %f\n", (double)(end - start) / CLOCKS_PER_SEC);  

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

void shellsort(int *vector, size_t vector_size){
  // Para cada incremento
  for (size_t i = vector_size/2; i > 2; i /= 2){
    
    // Ordena cada sublista
    for (size_t j = 0; j < i; j++)
      shellsort_incr(vector, j, i, vector_size);
  }

  // Ordena a lista final
  shellsort_incr(vector, 0, 1, vector_size);
}

void shellsort_incr(int *vector, size_t inicio, size_t incr, size_t vector_size){
  int aux;
  
  for (size_t i = inicio+incr; i < vector_size; i += incr)
    for (size_t j = i; ((j >= incr) && (*(vector + j) < *(vector + j-incr))); j -= incr){
      aux = *(vector + j);
      *(vector + j) = *(vector + j-incr);
      *(vector + j-incr) = aux;
    }
}

void merge_sort(int *vetor, int comeco, int fim){
    
  if (comeco < fim) {
    int meio = (fim+comeco)/2;

    merge_sort(vetor, comeco, meio);
    merge_sort(vetor, meio+1, fim);
    merge(vetor, comeco, meio, fim);
  }
}

void merge(int *vetor, int comeco, int meio, int fim) {
  int com_p1 = comeco, meio_p1 = meio+1, pos_aux = 0, tam = fim-comeco+1;
  int *vet_aux;
  
  // Alocando memória para o vetor auxiliar
  vet_aux = (int*)malloc(tam * sizeof(int));

  while(com_p1 <= meio && meio_p1 <= fim){
    if(*(vetor + com_p1) < *(vetor + meio_p1)) {
      *(vet_aux + pos_aux) = *(vetor + com_p1);
      com_p1++;
    } else {
      *(vet_aux + pos_aux) = *(vetor + meio_p1);
      meio_p1++;
    }
    pos_aux++;
  }

  while(com_p1 <= meio){  //Caso ainda haja elementos na primeira metade
    *(vet_aux + pos_aux) = *(vetor + com_p1);
    pos_aux++;
    com_p1++;
  }

  while(meio_p1 <= fim) {   //Caso ainda haja elementos na segunda metade
    *(vet_aux + pos_aux) = *(vetor + meio_p1);
    pos_aux++;
    meio_p1++;
  }

  for(pos_aux = comeco; pos_aux <= fim; pos_aux++){    //Move os elementos de volta para o vetor original
    *(vetor + pos_aux) = *(vet_aux + pos_aux - comeco);
  }

  free(vet_aux);
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