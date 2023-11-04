// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

long long N, T;

int main() {
    cin >> N >> T;
    long long res;
    if (T % 2 == 0 && N % 2 == 0) {
        cout << 3 * N / T - (N - 1) / T << endl;
    } else if (T % 2 == 0) {
        cout << "0\n";
    } else if (N % 2 == 0) {
        cout << (3 * N) / (T * 2) - (N - 1) / (T * 2) << endl;
    } else {
        cout << (3 * N + T) / (T * 2) - (N - 1 + T) / (T * 2) << endl;
    }
}