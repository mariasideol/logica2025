#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int seq[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    int count = 1; // Sempre marca o primeiro
    for (int i = 1; i < n; i++) {
        if (seq[i] != seq[i - 1]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
