#include <bits/stdc++.h>
using namespace std;
int n,q,psa[1005];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        // prefix sum array
        psa[i] = psa[i-1] + a;
    }
    for (int i = 0; i < q; ++i) {
        int l,r; cin >> l >> r;
        cout << psa[r]-psa[l-1] << " " << psa[r]/90 << " " << psa[r]/10 << "\n";
    }
}
