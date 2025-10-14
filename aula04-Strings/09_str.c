#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(char *str);
// Essa função concatena duas strings retornando o ponteiro da nova string
char *my_strcat(char *first_str, char *second_str);

int main(){
  /*
   * Alocando memória para as strings
   * [OBS:] eu menti antes, só precisa de cast em C++...
   * ...mas agora vocês já sabem... ;)
  */
  char *str_pointer_first = malloc(sizeof(char)*100);
  char *str_pointer_second = malloc(sizeof(char)*100);
  // verificando se a alocação foi bem sucedida
  if(str_pointer_first == NULL || str_pointer_second == NULL){
    printf("Erro na alocação de memória\n");
    return 1;
  }

  // Lendo primeira string
  printf("Digite a primeira string: ");
  fgets(str_pointer_first, 100, stdin);
  str_pointer_first[strcspn(str_pointer_first, "\n")] = '\0';

  // Lendo segunda string
  printf("Digite a segunda string: ");
  fgets(str_pointer_second, 100, stdin);
  str_pointer_second[strcspn(str_pointer_second, "\n")] = '\0';

  // Chamando a função que retorna o endereço da nova string
  char *str_point_cat = NULL;
  str_point_cat = my_strcat(str_pointer_first, str_pointer_second);

  printf("Strings concatenadas: %s\n", str_point_cat);

  free(str_pointer_first);
  free(str_pointer_second);
  free(str_point_cat);

  return 0;
}

char *my_strcat(char *first_str, char *second_str){

  // Primeiro precisamos saber o tamanho da nova string...
  size_t first_str_size = my_strlen(first_str);
  size_t second_str_size = my_strlen(second_str);
  // ...não esqueça do '\0'
  size_t str_size = first_str_size + second_str_size + 1;

  // Esse vai apontar para a nova string na heap
  char *p_str_result = malloc(sizeof(char)*str_size);
  // verificando se a alocação foi bem sucedida
  if(p_str_result == NULL){
    printf("Erro na alocação de memória\n");
    return NULL;
  }
  
  // Copiando a primeira string, sem copiar o '\0' no final
  for(size_t i = 0; i < first_str_size; i++)
    *(p_str_result + i) = *(first_str + i);

  // Copiando a primeira string, incluindo o '\0' no final
  for(size_t i = 0; i <= second_str_size; i++)
    *(p_str_result + first_str_size + i) = *(second_str + i);

  return p_str_result;
}

size_t my_strlen(char *str){
  size_t i = 0;

  // Percorre a string até encontrar o '\0'
  while(*(str + i) != '\0'){
    i++;
  }

  return i--;
}