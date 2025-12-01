#include <stdlib.h>
#include <stdio.h>

typedef struct Carta{
  char naipe;
  char tipo;
  struct Carta *proxima_carta;
} Carta;

void inserir(Carta **topo, char n, char t);
int remover(Carta **topo, char *n, char *t);
void print(Carta *topo);

int main(){
  Carta *topo = NULL;

  inserir(&topo, 'D', 'P');
  inserir(&topo, 'R', 'C');
  inserir(&topo, 'A', 'E');

  print(topo);

  char naipe, tipo, valido;
  valido = remover(&topo, &naipe, &tipo);
  valido = remover(&topo, &naipe, &tipo);
  valido = remover(&topo, &naipe, &tipo);
  valido = remover(&topo, &naipe, &tipo);
  if(!valido){
    printf("Removido: %c%c\n", naipe, tipo);
  } else {
    printf("Pilha vazia!\n");
  }

  print(topo);
  
}

void inserir(Carta **topo, char n, char t){
  Carta *nova_carta = NULL;
  nova_carta = malloc(sizeof(Carta));

  nova_carta->naipe = n;
  nova_carta->tipo = t;
  nova_carta->proxima_carta = *topo;
  *topo = nova_carta;
}

int remover(Carta **topo, char *n, char *t){
  if(*topo == NULL){
    return 1;
  }

  Carta *aux = *topo;
  *topo = aux->proxima_carta;
  *n = aux->naipe;
  *t = aux->tipo;

  free(aux);

  return 0;
}

void print(Carta *topo){
  while(topo != NULL){
    printf("%c%c\n", topo->naipe, topo->tipo);
    topo = topo->proxima_carta;
  }
}