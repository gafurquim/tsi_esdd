#include <stdio.h>
#include <string.h>

int main(){
  // Somente um pouquinho de lixo antes...
  char str_garbage_1 = 'A';
  char str_hello[13] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
  // ...e depois da declaração...
  char str_garbage_2 = 'C';

  printf("Size: %zu\n", strlen(str_hello));

  // Perceba que, sem o '\0' no final, o strlen erra na contagem
  size_t str_size = strlen(str_hello);
  for(size_t i = 0; i < str_size; i++){
    printf("[%zu]: %c\n", i, str_hello[i]);
  }

  printf("%s\n", str_hello);

  return 0;
}