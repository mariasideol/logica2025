int main() {
    int N;
    char line[1001];

    scanf("%d", &N);
    getchar(); // Consumir o \n após o número

    for(int t = 0; t < N; t++) {
        fgets(line, 1001, stdin);

        int len = strlen(line);

        // Remove \n no final, se houver
        if(line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }

        // Primeira parte: deslocar +3 as letras (maiúsculas e minúsculas)
        for(int i = 0; i < len; i++) {
            if((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
                line[i] += 3;
            }
        }

        // Segunda parte: inverter a linha
        for(int i = 0; i < len/2; i++) {
            char temp = line[i];
            line[i] = line[len - i - 1];
            line[len - i - 1] = temp;
        }

        // Terceira parte: deslocar -1 os caracteres da segunda metade (metade truncada)
        for(int i = len/2; i < len; i++) {
            line[i] -= 1;
        }

        printf("%s\n", line);
    }

    return 0;
}
