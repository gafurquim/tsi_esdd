#include <stdio.h>

typedef struct {
  int numerador;
  int denominador;
}Num_Racional;

void num_racional_init(Num_Racional *num, int numer, int den);
Num_Racional soma(Num_Racional num_1, Num_Racional num_2);
Num_Racional multiplicar(Num_Racional num_1, Num_Racional num_2);
int iguais(Num_Racional num_1, Num_Racional num_2);
int print_num(Num_Racional num);

int main(){
  Num_Racional nr1, nr2, nr3;

  num_racional_init(&nr1, 5, 7);
  num_racional_init(&nr2, 15, 2);

  nr3 = soma(nr1, nr2);
  
  print_num(nr1);
  print_num(nr2);
  print_num(nr3);

  return 0;
}

void num_racional_init(Num_Racional *num, int numer, int den){
  num->numerador = numer;
  num->denominador = den;
}

int print_num(Num_Racional num){
  printf("%d/%d\n", num.numerador, num.denominador);
}

Num_Racional soma(Num_Racional num_1, Num_Racional num_2){
  int num, den;

  den = num_1.denominador*num_2.denominador;
  num = ((den/num_1.denominador)*num_1.numerador)+
            ((den/num_2.denominador)*num_2.numerador);

  Num_Racional num_return;
  num_racional_init(&num_return, num, den);

  return num_return;
}