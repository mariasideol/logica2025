#include <stdio.h>

int main() {
    int t, guess, correct = 0;
    scanf("%d", &t); // Lê o tipo de chá correto

    for (int i = 0; i < 5; i++) {
        scanf("%d", &guess); // Lê o palpite do participante
        if (guess == t) {
            correct++; // Se o palpite estiver correto, incrementa
        }
    }

    printf("%d\n", correct); // Imprime o número de acertos
    return 0;
}
