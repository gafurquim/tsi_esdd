#include <stdio.h>
#include <string.h>

int main(){
  char str_garbage = 'A';
  char str_hello[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};

  printf("Size: %d\n", strlen(str_hello));

  /*
   * Mesmo que o 03_str.c, mas com '\0' no final...
   * ... formando uma string
   */
  for(int i = 0; i < strlen(str_hello); i++){
    printf("[%d]: %c\n", i, str_hello[i]);
  }

  printf("%s\n", str_hello);

  return 0;
}