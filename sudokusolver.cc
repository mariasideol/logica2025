// sudokusolver.cc - resolvedor clássico (backtracking)
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

bool resolver(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (podeColocar(grid, i, j, val)) {
                        grid[i][j] = val;
                        if (resolver(grid)) return true;
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
    return true;
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

    if (resolver(grid)) imprime(grid);
    else cout << "Sem solucao" << endl;
    return 0;
}
