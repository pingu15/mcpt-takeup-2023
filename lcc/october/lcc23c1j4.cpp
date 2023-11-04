// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N, K;
char grid[1000][1000];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (K == 0) {
                cin >> grid[i][j];
            }
            if (K == 90) {
                cin >> grid[j][N - i - 1];
            }
            if (K == 180) {
                cin >> grid[N - i - 1][N - j - 1];
            }
            if (K == 270) {
                cin >> grid[N - j - 1][i];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << (j == N - 1 ? "\n" : " ");
        }
    }
}