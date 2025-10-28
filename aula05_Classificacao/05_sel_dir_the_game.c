#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selecao_direta(int *vector, size_t vector_size);
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
  selecao_direta(int_pointer, vector_size);

  printf("Vetor ordenado: ");
  print_vector(int_pointer, vector_size);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void selecao_direta(int *vector, size_t vector_size){
  size_t i, next_min_pos, min, pos_primeira, pos_segunda;
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
      // Let's play a game
      printf("\nDescubra o pŕoximo passo, quais posições serão trocadas?\n");
      print_vector(vector, vector_size);
      printf("Digite a primeira posição [%zu, %zu]: ", i, min);
      scanf("%zu", &pos_primeira);
      printf("Digite a segunda posição [%zu, %zu]: ", i, min);
      scanf("%zu", &pos_segunda);
      
      // Comparando trocas
      while(!((pos_primeira == i && pos_segunda == min) || 
          (pos_primeira == min && pos_segunda == i))){
        printf("\nMovimento incorreto, tente novamente.\n");
        print_vector(vector, vector_size);
        printf("Digite a primeira posição [%zu, %zu]: ", i, min);
        scanf("%zu", &pos_primeira);
        printf("Digite a segunda posição [%zu, %zu]: ", i, min);
        scanf("%zu", &pos_segunda);
      }

      printf("\nMovimento correto\n");      
      aux = *(vector + i);
      *(vector + i) = *(vector + min);
      *(vector + min) = aux;
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
