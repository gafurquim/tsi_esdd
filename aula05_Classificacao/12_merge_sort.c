#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int *vetor, int comeco, int fim);
void merge(int *vetor, int comeco, int meio, int fim);
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

  // Ordenando o vetor
  // Vamos medir o tempo de execução
  clock_t start, end;
  start = clock();
  merge_sort(int_pointer, 0, vector_size-1);
  end = clock();
  printf("\nTempo de execução: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
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

void print_vector(int *vector, size_t vector_size){
  for(size_t i = 0; i < vector_size; i++){
    printf("%d ", *(vector + i));
  }
  printf("\n");
}