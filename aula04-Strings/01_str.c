#include <stdio.h>
#include <string.h>

int main(){
  char str_hello[] = "Hello, World!";

  printf("%s\n", str_hello);
  
  // Vamos ver o tamanho da string com strlen e sizeof
  printf("Tamanho da string com strlen: %zu\n", strlen(str_hello));
  printf("Tamanho da string com sizeof: %zu\n", sizeof(str_hello));

  return 0;
}