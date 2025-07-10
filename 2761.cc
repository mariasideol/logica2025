#include <stdio.h>

int main() {
    int a;
    float b;
    char c;
    char d[51];

    scanf("%d %f %c %[^\n]", &a, &b, &c, d);

    // Linha 1: sem espaço
    printf("%d%.6f%c%s\n", a, b, c, d);

    // Linha 2: com tabulações (8 espaços cada)
    printf("%d\t%.6f\t%c\t%s\n", a, b, c, d);

    // Linha 3: com 10 espaços fixos (exatamente 10 posições)
    printf("%10d%10.6f%10c%10s\n", a, b, c, d);

    return 0;
}
