// sudokusolverRec.cc - resolvedor recursivo
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

bool resolverRec(int i, int j, vector<vector<int>>& grid) {
    if (i == N) return true;
    if (grid[i][j] != 0) {
        if (j == N - 1) return resolverRec(i + 1, 0, grid);
        else return resolverRec(i, j + 1, grid);
    }
    for (int val = 1; val <= 9; val++) {
        if (podeColocar(grid, i, j, val)) {
            grid[i][j] = val;
            if (j == N - 1) {
                if (resolverRec(i + 1, 0, grid)) return true;
            } else {
                if (resolverRec(i, j + 1, grid)) return true;
            }
            grid[i][j] = 0;
        }
    }
    return false;
}

void imprime(const vector<vector<int>>& grid) {
    for (const auto& linha : grid) {
        for (int v : linha)
            cout << v << " ";
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

    if (resolverRec(0, 0, grid)) imprime(grid);
    else cout << "Sem solucao" << endl;
    return 0;
}
