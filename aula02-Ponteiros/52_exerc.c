#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int *array, int size);
// Utilize ponteiros para implementar a função
// Percorra o array utilizando ponteiros
int sumArray(/* implementar */);

int main(int argc, char const *argv[]){
    
  int array[10];

  fillArray(array, 10);

  int sum;
  sum = sumArray(/* implementar */);

  for(int i = 0; i < 10; i++){
    printf("Array[%d]: %d\n", i, *(array + i));
  }

  printf("\nSoma do array: %d\n", sum);
    
  return 0;
}

void fillArray(int *array, int size){
  // Inicializa o gerador de números aleatórios
  srand(time(0));

  for(int i = 0; i < size; i++){
    *(array + i) = rand() % 10;
  }
}

int sumArray(/* implementar */){
  // implementar
  return -1;
}
