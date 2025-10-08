#include <stdio.h>
#include <string.h>

int main(){
  // Somente um pouquinho de lixo antes...
  char str_garbage_1 = 'A';
  char str_hello[13] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
  // ...e depois da declaração...
  char str_garbage_2 = 'C';

  // Alguns compiladores colocam o '/0' automaticamente...
  // ... então, vamos apagar à força... :)
  str_hello[13] = 'B';

  printf("Size: %d\n", strlen(str_hello));

  // Perceba que, sem o '\0' no final, o strlen erra na contagem
  for(int i = 0; i < strlen(str_hello); i++){
    printf("[%d]: %c\n", i, str_hello[i]);
  }

  printf("%s\n", str_hello);

  return 0;
}