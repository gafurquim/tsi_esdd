/*
 *  Esse código tem erros para fins didático...
 *  ... não deve ser utilizado!
 */

#include <stdio.h>
#include <stdlib.h>

void fillArray(int array[], int size);

int main(){
  int size;

  printf("Digite o tamanho do array: ");
  scanf("%d", &size);
  int int_array[size];

  fillArray(int_array, size);

  for(int i = 0; i < size; i++){
    printf("%d\n", int_array[i]);
  }

  return 0;
}

void fillArray(int array[], int size){
  for(int i = 0; i < size; i++){
    array[i] = i;
  }
}