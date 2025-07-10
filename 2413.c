#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);           // Lê o número de pessoas que clicaram no 3º link
    int primeiro = 4 * t;      // Calcula o número de pessoas que clicaram no 1º link
    printf("%d\n", primeiro);  // Imprime o resultado
    return 0;
}
