/*
 * Somente demostração, não assustem....
 * ...vamos aprofundar nesse conteúdo futuramente
 */

#include <stdio.h>
#include <stdlib.h>

void fillArray(char (*array)[4], int size){
  for(int i = 0; i < size; i++){
    //*(array + i) = (i+1) * 10; // ainda funciona, mas...
    sprintf(*(array + i), "%d", (i + 1) * 10);
  }
}

int main(void){
  // Para caber "100" + '\0'
  char array[10][4];

  fillArray(array, 10);

  for(int i = 0; i < 10; i++){
    printf("Array[%d]: %s\n", i, *(array + i));
  }
  return 0;
}
