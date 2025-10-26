#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercao_direta_the_game(int *vector, size_t vector_size);
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

  printf("Vetor original:\n");
  print_vector(int_pointer, vector_size);

  // Ordenando o vetor
  insercao_direta_the_game(int_pointer, vector_size);

  printf("\nVetor ordenado:\n");
  print_vector(int_pointer, vector_size);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void insercao_direta_the_game(int *vector, size_t vector_size){
  size_t i = 1, pos_menor, pos_primeira, pos_segunda;
  int aux;

  while (i < vector_size){
    // Encontrando a posição do menor elemento
    pos_menor = i;

    // Deslocando o menor elemento para a posição correta
    while (pos_menor > 0 && *(vector + pos_menor-1) > *(vector + pos_menor)){
      // Let's play a game
      printf("\nDescubra o pŕoximo passo, quais posições serão trocadas?\n");
      print_vector(vector, vector_size);
      printf("Digite a primeira posição: ");
      scanf("%zu", &pos_primeira);
      printf("Digite a segunda posição: ");
      scanf("%zu", &pos_segunda);
      
      // Comparando trocas
      while(!((pos_primeira == pos_menor && pos_segunda == pos_menor-1) || 
          (pos_primeira == pos_menor-1 && pos_segunda == pos_menor))){
        printf("\nMovimento incorreto, tente novamente.\n");
        print_vector(vector, vector_size);
        printf("Digite a primeira posição: ");
        scanf("%zu", &pos_primeira);
        printf("Digite a segunda posição: ");
        scanf("%zu", &pos_segunda);
      }
      printf("\nMovimento correto\n");

      aux = *(vector + pos_menor);
      *(vector + pos_menor) = *(vector + pos_menor-1);
      *(vector + pos_menor-1) = aux;
      pos_menor--;
    }
    i++;
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