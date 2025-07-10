#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    char line[201];

    scanf("%d", &N);
    getchar(); // Consumir \n depois do número

    for (int t = 0; t < N; t++) {
        int freq[26] = {0}; // Frequência das letras

        fgets(line, 201, stdin);
        int len = strlen(line);

        for (int i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                char lower = tolower(line[i]);
                freq[lower - 'a']++;
            }
        }

        // Encontrar a maior frequência
        int max = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max)
                max = freq[i];
        }

        // Imprimir as letras com a maior frequência em ordem alfabética
        for (int i = 0; i < 26; i++) {
            if (freq[i] == max)
                printf("%c", 'a' + i);
        }
        printf("\n");
    }

    return 0;
}
