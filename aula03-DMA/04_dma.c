#include <stdio.h>
#include <stdlib.h>

int main(){
  int size = 100;
  int *int_pointer = NULL;

  int_pointer = (int*) malloc(size*sizeof(int));

  for(int i = 0; i < size; i++){
    int_pointer[i] = i;
  }

  for(int i = 0; i < size; i++){
    printf("%d\n", int_pointer[i]);
  }

  free(int_pointer);

  return 0;
}