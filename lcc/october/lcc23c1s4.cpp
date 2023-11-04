// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N, M, K, MOD = 1e9 + 7;
long long adj[101][101][101]; // adj[k][i][j] = number of times i and j are adjacent after k iterations
long long freq[101]; // freq[i] = number of times i appears in the array
int a[2000];
vector<pair<int, int>> ins;

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        freq[a[i]]++;
        if(i == 0) continue;
        adj[0][a[i-1]][a[i]]++;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ins.push_back({a, b});
    }
    for (int k = 1; k <= K; k++) { // simulate K iterations
        for(int i = 0; i < M; i++) { // for each instruction
            for(int j = 1; j <= 100; j++) {
                int l = ins[i].first-j; // for every (j, l) pair where j+l = ins[i].first
                if(l <= 0 || l > 100) continue;
                adj[k][j][ins[i].second] += adj[k-1][j][l]; // insert ins[i].second after j
                adj[k][ins[i].second][l] += adj[k-1][j][l]; // insert ins[i].second before l
                freq[ins[i].second] += adj[k-1][j][l]; // update frequency of ins[i].second
                adj[k-1][j][l] = 0; // set to 0 to avoid double counting (see loop below)
            }
        }
        for(int i = 1; i <= 100; i++) { 
            for(int j = 1; j <= 100; j++) {
                adj[k][i][j] += adj[k-1][i][j]; // add leftover values from previous iteration
                adj[k][i][j] %= MOD;
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i <= 100; i++) {
        ans += freq[i]*i; // frequency * value gives total sum of given value
        ans %= MOD;
    }
    cout << ans << endl;
}