/*
 * Somente demostração, não assustem....
 * ...vamos aprofundar nesse conteúdo futuramente
 */

#include <stdio.h>
#include <stdlib.h>

void fillArray(char (*array)[4], int size){
  // iniciando o ponteiro no início do array
  char (*ptr)[4] = array;

  // Percebam o ptr++
  for(int i = 0; i < size; i++, ptr++){
    sprintf(*ptr, "%d", (i + 1) * 10);
  }
}

int main(void){
  char array[10][4];
  char (*ptr)[4] = array;

  fillArray(array, 10);

  for(int i = 0; i < 10; i++, ptr++){
    printf("Array[%d]: %s\n", i, *ptr);
  }

  return 0;
}