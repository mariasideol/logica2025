// sudoku++.cc - Verificador para Sudoku++ (valores de 1 a 10)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 10;

bool verificaSudokuPlus(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        set<int> linha, coluna;
        for (int j = 0; j < N; j++) {
            if (grid[i][j] < 1 || grid[i][j] > 10 || grid[j][i] < 1 || grid[j][i] > 10)
                return false;
            linha.insert(grid[i][j]);
            coluna.insert(grid[j][i]);
        }
        if (linha.size() != 10 || coluna.size() != 10)
            return false;
    }
    for (int x = 0; x < N; x += 2)
        for (int y = 0; y < N; y += 5) {
            set<int> bloco;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 5; j++) {
                    int val = grid[x + i][y + j];
                    if (bloco.count(val)) return false;
                    bloco.insert(val);
                }
        }
    return true;
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    cout << (verificaSudokuPlus(grid) ? "SIM" : "NAO") << endl;
    return 0;
}
