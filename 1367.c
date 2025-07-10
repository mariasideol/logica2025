#include <stdio.h>
#include <string.h>

#define MAX 26

typedef struct {
    int time;
    int incorrects;
    int solved;
} Problem;

int main() {
    int N;
    while (scanf("%d", &N), N != 0) {
        Problem problems[MAX] = {0}; // Zera todos os problemas
        char id;
        int time;
        char result[10];
        
        for (int i = 0; i < N; i++) {
            scanf(" %c %d %s", &id, &time, result);
            int idx = id - 'A';

            if (problems[idx].solved)
                continue; // Ignora se já foi resolvido

            if (strcmp(result, "correct") == 0) {
                problems[idx].time = time + problems[idx].incorrects * 20;
                problems[idx].solved = 1;
            } else {
                problems[idx].incorrects++;
            }
        }

        int solved_count = 0, total_time = 0;
        for (int i = 0; i < MAX; i++) {
            if (problems[i].solved) {
                solved_count++;
                total_time += problems[i].time;
            }
        }

        printf("%d %d\n", solved_count, total_time);
   }

    return 0;
}
