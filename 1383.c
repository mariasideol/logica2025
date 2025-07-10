#include <stdio.h>
#include <stdbool.h>

bool check_rows(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        bool seen[10] = { false };
        for (int j = 0; j < 9; j++) {
            int val = grid[i][j];
            if (seen[val]) return false;
            seen[val] = true;
        }
    }
    return true;
}

bool check_columns(int grid[9][9]) {
    for (int j = 0; j < 9; j++) {
        bool seen[10] = { false };
        for (int i = 0; i < 9; i++) {
            int val = grid[i][j];
            if (seen[val]) return false;
            seen[val] = true;
        }
    }
    return true;
}

bool check_subgrids(int grid[9][9]) {
    for (int start_row = 0; start_row < 9; start_row += 3) {
        for (int start_col = 0; start_col < 9; start_col += 3) {
            bool seen[10] = { false };
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int val = grid[start_row + i][start_col + j];
                    if (seen[val]) return false;
                    seen[val] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, grid[9][9];

    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        // Leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("Instancia %d\n", k);

        // Verificação das regras do Sudoku
        if (check_rows(grid) && check_columns(grid) && check_subgrids(grid)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        printf("\n"); // linha em branco após cada instância
    }

    return 0;
}
