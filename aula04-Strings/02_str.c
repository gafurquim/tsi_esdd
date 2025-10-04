#include <stdio.h>
#include <string.h>

int main(){
  char str_hello[] = "Hello, World!";

  for(int i = 0; i < strlen(str_hello); i++){
    printf("[%d]: %c\n", i, str_hello[i]);
  }

  return 0;
}