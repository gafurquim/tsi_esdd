#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array){
  for(int i = 0; i < 10; i++){
    *(array + i) = (i+1) * 10;
  }
}

int main(int argc, char const *argv[]){
    
  int array[10];

  fillArray(array);

  for(int i = 0; i < 10; i++){
    printf("Array[%d]: %d\n", i, *(array + i) );
  }
    
  return 0;
}