#include <stdio.h>

int main() {
    char o;
    double M[12][12], sum = 0.0;
    int count = 0;

    // Leitura da operação: 'S' (soma) ou 'M' (média)
    scanf(" %c", &o);

    // Leitura dos 144 valores da matriz 12x12
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Soma dos elementos acima da diagonal principal
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            sum += M[i][j];
            count++;
        }
    }

    // Impressão do resultado
    if (o == 'S') {
        printf("%.1lf\n", sum);
    } else if (o == 'M') {
        printf("%.1lf\n", sum / count);
    }

    return 0;
}
