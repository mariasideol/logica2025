#include <stdio.h>
#include <math.h>

int main() {
    int N, x, y;

    scanf("%d", &N);

    while (N--) {
        scanf("%d %d", &x, &y);

        int rafael = pow(3 * x, 2) + pow(y, 2);
        int beto = 2 * pow(x, 2) + pow(5 * y, 2);
        int carlos = -100 * x + pow(y, 3);

        if (rafael > beto && rafael > carlos) {
            printf("Rafael ganhou\n");
        } else if (beto > carlos) {
            printf("Beto ganhou\n");
        } else {
            printf("Carlos ganhou\n");
        }
    }

    return 0;
}
