#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int *vetor, int comeco, int fim);
void merge(int *vetor, int comeco, int meio, int fim);
void print_vector_shift(int *vector, size_t vector_size, size_t shift);

int main(){
  size_t vector_size = 20;

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
  print_vector_shift(int_pointer, vector_size, 0);

  // Ordenando o vetor
  merge_sort(int_pointer, 0, vector_size-1);

  printf("\nVetor ordenado:\n");
  print_vector_shift(int_pointer, vector_size, 0);

  // Nunca esqueça de liberar a memória alocada
  free(int_pointer);

  return 0;
}

void merge_sort(int *vetor, int comeco, int fim){
  char ch;
    
  if (comeco < fim) {
    printf("\nQuebrando o vetor:\n");
    print_vector_shift(vetor, fim+1, comeco);
    ch = getchar();

    int meio = (fim+comeco)/2;

    merge_sort(vetor, comeco, meio);
    merge_sort(vetor, meio+1, fim);
    merge(vetor, comeco, meio, fim);
  } else {
    printf("\nPara a recursividade [elemento: %d]!\n", *(vetor + comeco));
  }
}

void merge(int *vetor, int comeco, int meio, int fim) {
  int com_p1 = comeco, com_p2 = meio+1, pos_aux = 0, tam = fim-comeco+1;
  int *vet_aux;
  char ch;

  // Alocando memória para o vetor auxiliar
  vet_aux = (int*)malloc(tam * sizeof(int));
  printf("\nJuntando (merging) os vetores:\n");
  print_vector_shift(vetor + com_p1, meio-com_p1+1, com_p1);
  print_vector_shift(vetor + com_p2, fim-com_p2+1, com_p2);
  ch = getchar();

  // Copiando os valores do menor para o vetor auxiliar
  while(com_p1 <= meio && com_p2 <= fim) {
    if(*(vetor + com_p1) < *(vetor + com_p2)) {
      *(vet_aux + pos_aux) = *(vetor + com_p1);
      com_p1++;
    } else {
      *(vet_aux + pos_aux) = *(vetor + com_p2);
      com_p2++;
    }
    pos_aux++;
  }

  // Copiando os valores restantes do primeiro vetor
  // ... ocorre quando o primeiro vetor é maior que o segundo
  while(com_p1 <= meio) { 
    *(vet_aux + pos_aux) = *(vetor + com_p1);
    pos_aux++;
    com_p1++;
  }

  // Copiando os valores restantes do segundo vetor
  // ... ocorre quando o segundo vetor é maior que o primeiro
  while(com_p2 <= fim) {
    *(vet_aux + pos_aux) = *(vetor + com_p2);
    pos_aux++;
    com_p2++;
  }

  // Copiando os valores do vetor auxiliar para o vetor original
  for(pos_aux = comeco; pos_aux <= fim; pos_aux++){
    *(vetor + pos_aux) = *(vet_aux + pos_aux - comeco);
  }

  printf("Vetor 'merged':\n");
  print_vector_shift(vet_aux, tam, comeco);
  ch = getchar();

  free(vet_aux);
}

void print_vector_shift(int *vector, size_t vector_size, size_t shift){
  printf("Posição: ");
  for(size_t i = 0; i < vector_size; i++){
    printf("%3zu", i+shift);
  }
  printf("\nValores: ");
  for(size_t i = 0; i < vector_size; i++){
    printf("%3d", *(vector + i));
  }
  printf("\n");
}
