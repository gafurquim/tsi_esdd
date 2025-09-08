/*
 *  Esse código é propositalmente ineficiente...
 *  ... para fins didático, não deve ser utilizado!
 */
#include <stdio.h>

void fillArray(int array[], int size);

 int main(){
  // Implementar utilizando um array 
  // do tamanho digitado pelo usuário
  printf("Digite o tamanho do array: ");
  int size;
  scanf("%d", &size);

  // implementar
 
  fillArray(array, size);
 
  for(int i=0; i<size; i++){
    printf("%d\n", array[i]);
  }

  printf("Pressione qualquer tecla para sair...\n");
  getchar();
 
  return 0;
 }

void fillArray(int array[], int size){
  for(int i=0; i<size; i++){
    array[i] = i;
  }
}