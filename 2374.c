#include <stdio.h>

int main() {
    int N, M;
    scanf("%d", &N);  // Pressão desejada
    scanf("%d", &M);  // Pressão lida

    printf("%d\n", N - M);  // Diferença entre as pressões
    return 0;
}
