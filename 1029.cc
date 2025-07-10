#include <stdio.h>

int fib_calls[40];     // Armazena o número de chamadas recursivas
int fib_results[40];   // Armazena o valor de Fibonacci já calculado

int fibonacci(int n) {
    if (n == 0) {
        fib_calls[n] = 0;
        return fib_results[n] = 0;
    }
    if (n == 1) {
        fib_calls[n] = 0;
        return fib_results[n] = 1;
    }

    if (fib_results[n] != -1) return fib_results[n];

    int a = fibonacci(n - 1);
    int b = fibonacci(n - 2);
    fib_calls[n] = fib_calls[n - 1] + fib_calls[n - 2] + 2;

    return fib_results[n] = a + b;
}

int main() {
    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);

        // Inicializa arrays
        for (int j = 0; j <= x; j++) {
            fib_results[j] = -1;
            fib_calls[j] = 0;
        }

        int result = fibonacci(x);
        printf("fib(%d) = %d calls = %d\n", x, fib_calls[x], result);
    }

    return 0;
}
