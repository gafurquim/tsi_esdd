#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Estrutura de decisão
    if (numero >= 0) {
        printf("O número %d é positivo ou zero.\n", numero);
    } else {
        printf("O número %d é negativo.\n", numero);
    }

    printf("Fim do programa.\n");

    return 0;
}
