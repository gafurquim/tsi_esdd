/*
 *  Esse código tem erros para fins didático...
 *  ... não deve ser utilizado
 */

#include <stdio.h>

int main(){
  int size = 100;
  int *int_pointer;

  for(int i=0; i<size; i++){
    int_pointer[i] = i;
  }

  for(int i=0; i<size; i++){
    printf("%d\n", int_pointer[i]);
  }

  return 0;
}