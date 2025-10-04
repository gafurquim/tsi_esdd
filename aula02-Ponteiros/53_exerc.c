#include <stdio.h>

// imprimir os valores das posições do vetor
void print_array(int *pos, int size);

int main(){
  int array_int[7];

  for(int i = 0; i < 7; i++){
    *(array_int + i) = i;
  }

  print_array(/* implementar */);

  return 0;
}

void print_array(int *pos, int size){
  // implementar
}