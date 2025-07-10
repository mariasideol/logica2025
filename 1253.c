#include <stdio.h>
#include <string.h>

int main() {
    int N, shift;
    char text[51];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", text);
        scanf("%d", &shift);

        int len = strlen(text);
        for (int j = 0; j < len; j++) {
            // Faz o deslocamento à esquerda (decodificar)
            text[j] = (text[j] - 'A' - shift + 26) % 26 + 'A';
        }
        printf("%s\n", text);
    }

    return 0;
}
