#include <stdio.h>
#include <string.h>

int main(){
  char str_garbage = 'A';
  char str_hello[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
  char str_garbage_2 = 'C';

  printf("Size: %zu\n", strlen(str_hello));

  /*
   * Mesmo que o 03_str.c, mas com '\0' no final...
   * ... formando uma string
   */
  size_t str_size = strlen(str_hello);
  for(size_t i = 0; i < str_size; i++){
    printf("[%zu]: %c\n", i, str_hello[i]);
  }

  printf("%s\n", str_hello);

  return 0;
}