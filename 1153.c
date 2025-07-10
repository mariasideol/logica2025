#include <stdio.h>
 
int main() {
    int n, i, fatorial = 1;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        fatorial *= i;
    }
    printf("%d\n", fatorial);
    return 0;
}
