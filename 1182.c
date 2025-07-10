#include <stdio.h>

int main() {
    int c, i;
    char t;
    double m[12][12], sum = 0.0;

    // Entrada da coluna e do tipo de operação
    scanf("%d", &c);
    getchar(); // Consome o '\n' após o número
    scanf("%c", &t);

    // Leitura da matriz 12x12
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

    // Soma dos elementos da coluna escolhida
    for (i = 0; i < 12; i++) {
        sum += m[i][c];
    }

    // Imprime resultado com uma casa decimal
    if (t == 'S') {
        printf("%.1lf\n", sum);
    } else if (t == 'M') {
        printf("%.1lf\n", sum / 12.0);
    }

    return 0;
}
