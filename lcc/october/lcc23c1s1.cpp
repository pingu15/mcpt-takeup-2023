// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<pair<int, int>> arr;
vector<int> sorted;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr.push_back({a, N - i - 1});
    }
    sort(arr.begin(), arr.end()); // first sort by fighting value with priority given to high index
    for (int i = 0; i < K; i++) {
        sorted.push_back(N - arr[i].second);
    }
    sort(sorted.begin(), sorted.end()); // sort K highest priority pairs by index
    for (int i = 0; i < K; i++) {
        cout << sorted[i] << (i == K - 1 ? "\n" : " "); // print out the indices
    }
}