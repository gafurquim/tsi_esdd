#include <stdio.h>
#include <string.h>

int main(){
  char str_hello[] = "Hello, World!";

  printf("Imprimindo com strlen:\n");
  for(int i = 0; i < strlen(str_hello); i++){
    printf("[%d]: %c\n", i, *(str_hello + i));
  }

  printf("\nImprimindo com sizeof:\n");
  for(int i = 0; i < sizeof(str_hello) - 1; i++){
    printf("[%d]: %c\n", i, *(str_hello + i));
  }

  return 0;
}