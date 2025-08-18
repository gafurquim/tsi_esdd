#include <stdio.h>

int main() {
    // Exemplo com "for"
    printf("Exemplo de loop 'for':\n");
    for (int i = 1; i <= 5; i++) {
        printf("Contagem: %d\n", i);
    }

    // Exemplo com while
    printf("\nExemplo de loop 'while':\n");
    int numero;
    
    printf("Digite um número (0 para sair): ");
    scanf("%d", &numero);

    while (numero != 0) {
        if (numero % 2 == 0) {
            printf("O número %d é par.\n", numero);
        } else {
            printf("O número %d é ímpar.\n", numero);
        }

        printf("Digite outro número (0 para sair): ");
        scanf("%d", &numero);
    }

    printf("Programa encerrado.\n");

    return 0;
}
