// sudokusolverFinal.cc - resolvedor recursivo com todas as soluções
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 9;
int total = 0;

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

void imprime(const vector<vector<int>>& grid) {
    cout << "Solucao " << ++total << ":\n";
    for (const auto& linha : grid) {
        for (int v : linha)
            cout << v << " ";
        cout << endl;
    }
    cout << endl;
}

void resolverTodas(int i, int j, vector<vector<int>>& grid) {
    if (i == N) {
        imprime(grid);
        return;
    }
    if (grid[i][j] != 0) {
        if (j == N - 1) resolverTodas(i + 1, 0, grid);
        else resolverTodas(i, j + 1, grid);
        return;
    }
    for (int val = 1; val <= 9; val++) {
        if (podeColocar(grid, i, j, val)) {
            grid[i][j] = val;
            if (j == N - 1) resolverTodas(i + 1, 0, grid);
            else resolverTodas(i, j + 1, grid);
            grid[i][j] = 0;
        }
    }
}

int main() {
    FILE* f = fopen("input2.txt", "r");
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fscanf(f, "%d", &grid[i][j]);
    fclose(f);

    resolverTodas(0, 0, grid);
    if (total == 0) cout << "Sem solucao" << endl;
    return 0;
}
