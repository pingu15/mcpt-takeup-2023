// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> v;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << N + 1 - (upper_bound(v.begin(), v.end(), S) - v.begin()) << "\n"; // Binary search for rank
    cout << max(v[N - 1], S) << " " << min(v[0], S) << "\n";
}