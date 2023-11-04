// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, int> brand;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        brand[s]++;
    }
    int ans = 0;
    for (auto [k, v] : brand) {
        ans += v % M; // add remaining candies after M days
    }
    cout << ans << endl;
}