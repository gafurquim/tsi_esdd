/*
 * Implementação de um algoritmo de ordenação merge sort
 * 
 * Essa é outro algoritmo de classificação por intercalação
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int *vetor, int comeco, int fim);
void merge(int *vetor, int comeco, int meio, int fim);
void print_vector(int *vector, size_t vector_size);
int busca_binaria(int *vector, size_t vector_size, int value);
int busca_por_interpolacao(int *vector, size_t vector_size, int value);
int busca_sequencial(int *vector, size_t vector_size, int value);

int main(){
  size_t vector_size = 100000;

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
    *(int_pointer + i) = rand() % 100000000;
  }

  //printf("Vetor original: ");
  //print_vector(int_pointer, vector_size);

  // Ordenando o vetor
  merge_sort(int_pointer, 0, vector_size-1);

  printf("Vetor ordenado: ");
  print_vector(int_pointer, vector_size);

  printf("Digite um valor para busca: ");
  int value;
  scanf("%d", &value);

  clock_t start, end;
  start = clock();
  int posicao = busca_por_interpolacao(int_pointer, vector_size, value);
  end = clock();

  printf("Tempo de execução (por interpolação): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  if(posicao == -1){
    printf("Valor não encontrado\n");
  } else {
    printf("Valor encontrado na posição %d\n", posicao);
  }

  start = clock();
  posicao = busca_binaria(int_pointer, vector_size, value);
  end = clock();

  printf("Tempo de execução (binária): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  if(posicao == -1){
    printf("Valor não encontrado\n");
  } else {
    printf("Valor encontrado na posição %d\n", posicao);
  }

  start = clock();
  posicao = busca_sequencial(int_pointer, vector_size, value);
  end = clock();

  printf("Tempo de execução (sequencial): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  if(posicao == -1){
    printf("Valor não encontrado\n");
  } else {
    printf("Valor encontrado na posição %d\n", posicao);
  }

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

int busca_binaria(int *vector, size_t vector_size, int value){
  int limite_inferior = 0, limite_superior = vector_size-1, proxima_posicao;

  while(limite_inferior <= limite_superior){
    proxima_posicao = (limite_superior + limite_inferior) / 2;
    if(*(vector + proxima_posicao) == value){
      return proxima_posicao;
    } else if(*(vector + proxima_posicao) < value){
      limite_inferior = proxima_posicao+1;
    } else {
      limite_superior = proxima_posicao-1;
    }
  }

  return -1;
}

int busca_por_interpolacao(int *vector, size_t vector_size, int value){
  int limite_inferior = 0, limite_superior = vector_size-1, proxima_posicao;

  while(limite_inferior <= limite_superior){
    proxima_posicao = limite_inferior + (limite_superior - limite_inferior) * ((value - *(vector + limite_inferior)) / (*(vector + limite_superior) - *(vector + limite_inferior)));
    if(*(vector + proxima_posicao) == value){
      return proxima_posicao;
    } else if(*(vector + proxima_posicao) < value){
      limite_inferior = proxima_posicao+1;
    } else {
      limite_superior = proxima_posicao-1;
    }
  }

  return -1;
}

int busca_sequencial(int *vector, size_t vector_size, int value){

  for(int i = 0; i < vector_size; i++){
    if(*(vector + i) == value){
      return i;
    }
  }

  return -1;
}
