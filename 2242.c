#include <stdio.h>
#include <string.h>

int main() {
    char str[51], vowels[51];
    int len, v = 0;

    scanf("%s", str);
    len = strlen(str);

    // Extrai apenas as vogais
    for (int i = 0; i < len; i++) {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') {
            vowels[v++] = str[i];
        }
    }

    // Verifica se a sequência de vogais é palíndromo
    int palindrome = 1;
    for (int i = 0; i < v/2; i++) {
        if (vowels[i] != vowels[v - i - 1]) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
