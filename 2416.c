#include <stdio.h>

int main() {
    int C, N;
    scanf("%d %d", &C, &N);
    
    int ponto_final = C % N;

    printf("%d\n", ponto_final);

    return 0;
}
