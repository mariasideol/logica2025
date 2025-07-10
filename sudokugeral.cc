// sudokugeral.cc - Suporte a qualquer dimensão
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool verificaQuadrado(const vector<vector<int>>& grid, int boxR, int boxC, int B) {
    int N = grid.size();
    for (int x = 0; x < N; x += B)
        for (int y = 0; y < N; y += B) {
            set<int> bloco;
            for (int i = 0; i < B; i++)
                for (int j = 0; j < B; j++) {
                    int val = grid[x + i][y + j];
                    if (val < 1 || val > N || bloco.count(val))
                        return false;
                    bloco.insert(val);
                }
        }
    return true;
}

bool verificaSudokuGeral(const vector<vector<int>>& grid) {
    int N = grid.size();
    int B = (int)sqrt(N);
    for (int i = 0; i < N; i++) {
        set<int> linha, coluna;
        for (int j = 0; j < N; j++) {
            if (grid[i][j] < 1 || grid[i][j] > N)
                return false;
            linha.insert(grid[i][j]);
            coluna.insert(grid[j][i]);
        }
        if (linha.size() != N || coluna.size() != N)
            return false;
    }
    return verificaQuadrado(grid, N, N, B);
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    cout << (verificaSudokuGeral(grid) ? "SIM" : "NAO") << endl;
    return 0;
}
