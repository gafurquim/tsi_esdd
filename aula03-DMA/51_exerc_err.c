// Implementar uma função que desloca os valores de um array para a direita
#include <stdlib.h>

int main(){
  int *my_little_pointer = NULL;

  my_little_pointer = (int*) malloc(10*sizeof(int));

  for(int i = 0; i < 10; i++)
    *(my_little_pointer + i) = i*10;

  shift(my_little_pointer);

  free(my_little_pointer);

  return 0;
}