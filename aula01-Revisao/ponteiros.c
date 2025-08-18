/*
 * Ponteiros permitem referenciar endereços de objetos em memória...
 * ... assim como o próprio objeto, ou seja, seu valor
 */

#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;
    printf("%d\n", *p);
    return 0;
}