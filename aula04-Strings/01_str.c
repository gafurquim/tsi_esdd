#include <stdio.h>
#include <string.h>

int main(){
  char str_hello[] = "Hello, World!";

  printf("%s\n", str_hello);
  printf("Tamanho da string com strlen: %d\n", strlen(str_hello));
  printf("Tamanho da string com sizeof: %d\n", sizeof(str_hello));

  return 0;
}