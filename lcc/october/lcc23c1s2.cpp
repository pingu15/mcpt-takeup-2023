// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int C, N;
char L;
char a[100000];

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> a[i];
    }
    cin >> L >> N;
    int ans = 0;
    for (int i = 0; i < C; i++) {
        if (a[i] >= '1' && a[i] <= '9' && a[i] - '0' != N) // check if it is a number not equal to N
            ans++;
        if (a[i] == L) // check if it is the letter L
            ans++;
    }
    cout << ans << endl;
}