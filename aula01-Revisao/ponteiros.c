/*
 * Ponteiros permitem referenciar endereços de objetos em memória...
 * ... assim como o próprio objeto, ou seja, seu valor
 */

#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("Valor da variavel a: %d\n", a);
    printf("Endereco da variavel a: %p\n", &a);
    printf("Valor do ponteiro p: %d\n", p);
    printf("Valor do objeto apontado por p (valor de a): %d\n", *p);
    
    return 0;
}