#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array, int size);
void increaseArray(int array[], int size);

int main(int argc, char const *argv[]){
    
  int array[10];

  fillArray(array, 10);
  increaseArray(array, 10);

  for(int i = 0; i < 10; i++){
    printf("Array[%d]: %d/%d\n", i, *(array + i), array[i]);
  }
    
  return 0;
}

void fillArray(int *array, int size){
  for(int i = 0; i < size; i++){
    *(array + i) = (i+1) * 10;
  }
}

void increaseArray(int array[], int size){
  for(int i = 0; i < size; i++){
    array[i]++;
  }
}
