#include <stdio.h>
#include <stdlib.h>

int main() {
  int array[5] = {10, 20, 30, 40, 50};

  printf("Tamanho de um inteiro: %ld bytes\n", sizeof(int));

  printf("Indice | array[i] | *(array + i) | i[array] | Endereço\n");
  printf("-------|----------|--------------|----------|---------------\n");

  for (int i = 0; i < 5; i++) {
      printf(" %d     |   %d     |    %d        |   %d     | %p\n",
          i,
          array[i],
          *(array + i),
          i[array],
          (void*)(array + i)
      );
  }

  return 0;
}
