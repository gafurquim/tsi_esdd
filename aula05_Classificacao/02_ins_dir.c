
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercao_direta(int *vector, size_t vector_size);
void insercao_direta_pausada(int *vector, size_t vector_size);
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

  // Vamos medir o tempo de execução
  clock_t start, end;
  start = clock();
  insercao_direta(int_pointer, vector_size);
  end = clock();
  printf("\nTempo de execução: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
  
  //insercao_direta_pausada(int_pointer, vector_size);

  printf("Vetor ordenado: ");
  print_vector(int_pointer, vector_size);

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

void insercao_direta_pausada(int *vector, size_t vector_size){
  size_t i = 1, pos_menor;
  int aux;
  char ch; // somente para pausar a execução

  print_vector(vector, vector_size);
  printf("Pressione Enter para continuar...");
  ch = getchar();

  while (i < vector_size){
    // Encontrando a posição do menor elemento
    pos_menor = i;

    // Deslocando o menor elemento para a posição correta
    while (pos_menor > 0 && *(vector + pos_menor-1) > *(vector + pos_menor)){
      aux = *(vector + pos_menor);
      *(vector + pos_menor) = *(vector + pos_menor-1);
      *(vector + pos_menor-1) = aux;
      pos_menor--;
      
      // Passo a passo
      print_vector(vector, vector_size);
      printf("Pressione Enter para continuar...");
      ch = getchar();
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