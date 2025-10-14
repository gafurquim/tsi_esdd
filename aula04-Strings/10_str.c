#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(char *str);
// Essa função concatena inserindo a segunda string no final da primeira...
// ...o strcat original faz isso
void my_strcat_no_return(char *first_str, char *second_str);

int main(){
  size_t strs_size = 100;

  // Alocando memória para as strings
  char *str_pointer_first = malloc(sizeof(char)*strs_size);
  char *str_pointer_second = malloc(sizeof(char)*strs_size);
  // verificando se a alocação foi bem sucedida
  if(str_pointer_first == NULL || str_pointer_second == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  // Lendo primeira string, agora com classe
  printf("Digite a primeira string: ");
  if (fgets(str_pointer_first, strs_size, stdin) == NULL) {
      printf("Erro ou EOF detectado\n");
      return 1;
    }
  str_pointer_first[strcspn(str_pointer_first, "\n")] = '\0';

  // Lendo segunda string
  printf("Digite a segunda string: ");
  if (fgets(str_pointer_second, strs_size, stdin) == NULL) {
      printf("Erro ou EOF detectado\n");
      return 1;
  }
  str_pointer_second[strcspn(str_pointer_second, "\n")] = '\0';

  // Perceba que, nesse caso, assim como no strcat do string.h...
  // ...a primeira string deve ser grande o suficiente para suportar a ação de concatenar
  if(my_strlen(str_pointer_first) + my_strlen(str_pointer_second) >= strs_size){
    printf("Tamanho de strings não suportado!\n");
    free(str_pointer_first);
    free(str_pointer_second);
    return 1;
  }
  // Concatenando strings
  my_strcat_no_return(str_pointer_first, str_pointer_second);

  printf("Strings concatenadas: %s\n", str_pointer_first);

  free(str_pointer_first);
  free(str_pointer_second);

  return 0;
}

void my_strcat_no_return(char *first_str, char *second_str){

  // Tamanho da primeira string sem o '\0'
  size_t first_str_size = my_strlen(first_str);
  size_t second_str_size = my_strlen(second_str);

  /*
   * Copiando a segunda string, no final da primeira...
   * ...incluindo o '\0' no final da segunda string...
   * ...começando pela posição onde temos o '\0' da primeira string...
   * ...ou seja, '\0' da primeira string será apagado
  */
  for(size_t i = 0; i <= second_str_size; i++)
    *(first_str + first_str_size + i) = *(second_str + i);
}

size_t my_strlen(char *str){
  size_t i = 0;

  // Percorre a string até encontrar o '\0'
  while(*(str + i) != '\0'){
    i++;
  }

  return i--;
}