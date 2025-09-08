#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int *array, int size);
// Utilize ponteiros para implementar a função
// Percorra o array utilizando ponteiros
int searchNumber(/* implementar */);

int main(int argc, char const *argv[]){
    
  int array[10];
  int number=10;

  fillArray(array, 10);

  while(number > 9 || number < 0){
    printf("Digite um número entre 0 e 9: ");
    scanf("%d", &number);
  }

  int position;
  position = searchNumber(/* implementar */);

  for(int i = 0; i < 10; i++){
    printf("Array[%d]: %d\n", i, *(array + i));
  }

  if(position == -1){
    printf("Valor %d não encontrado no array.\n", number);
    return -1;
  }

  printf("\nValor %d encontrado na posição %d.\n", number, position);
    
  return 0;
}

void fillArray(int *array, int size){
  // Inicializa o gerador de números aleatórios
  srand(time(0));

  for(int i = 0; i < size; i++){
    *(array + i) = rand() % 10;
  }
}

int searchNumber(/* implementar */){
  // implementar
  return -1;
}