/*
 *  Esse código tem erros para fins didático...
 *  ... não deve ser utilizado!
 */

#include <stdio.h>

int main(){
  int *int_pointer;

  printf("Endereço do ponteiro: %p\n", int_pointer);
  printf("Valor do ponteiro: %d\n", *int_pointer);

  *int_pointer = 10;

  printf("Endereço do ponteiro: %p\n", int_pointer);
  printf("Valor do ponteiro: %d\n", *int_pointer);

  return 0;
}