// jogo.cc - Sudoku interativo
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 9;

bool podeColocar(const vector<vector<int>>& grid, int x, int y, int val) {
    for (int i = 0; i < N; i++)
        if (grid[x][i] == val || grid[i][y] == val)
            return false;
    int bx = x - x % 3, by = y - y % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[bx + i][by + j] == val)
                return false;
    return true;
}

void imprimeSudoku(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    FILE* f = fopen("input2.txt", "r");
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fscanf(f, "%d", &grid[i][j]);
    fclose(f);

    int x, y, val;
    while (true) {
        imprimeSudoku(grid);
        cout << "Digite linha coluna valor (0 0 0 para sair): ";
        cin >> x >> y >> val;
        if (x == 0 && y == 0 && val == 0) break;
        if (x < 1 || x > 9 || y < 1 || y > 9 || val < 1 || val > 9) {
            cout << "Entrada invalida!" << endl;
            continue;
        }
        if (grid[x - 1][y - 1] != 0) {
            cout << "Celula ja preenchida!" << endl;
            continue;
        }
        if (podeColocar(grid, x - 1, y - 1, val))
            grid[x - 1][y - 1] = val;
        else
            cout << "Movimento invalido!" << endl;
    }

    cout << "Final do jogo:" << endl;
    imprimeSudoku(grid);
    return 0;
}
