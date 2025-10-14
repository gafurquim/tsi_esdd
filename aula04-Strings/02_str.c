#include <stdio.h>
#include <string.h>

int main(){
  char str_hello[] = "Hello, World!";

  printf("Imprimindo com strlen:\n");
  for(size_t i = 0; i < strlen(str_hello); i++){
    printf("[%zu]: %c\n", i, *(str_hello + i));
  }

  printf("\nImprimindo com sizeof:\n");
  for(size_t i = 0; i < sizeof(str_hello); i++){
    printf("[%zu]: %c\n", i, *(str_hello + i));
  }

  return 0;
}