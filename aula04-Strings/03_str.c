#include <stdio.h>
#include <string.h>

int main(){
  char str_garbage = 'A';
  char str_hello[13] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

  printf("Size: %d\n", strlen(str_hello));

  // Perceba que, sem o '\0' no final, o strlen erra na contagem
  for(int i = 0; i < strlen(str_hello); i++){
    printf("[%d]: %c\n", i, str_hello[i]);
  }

  printf("%s\n", str_hello);

  return 0;
}