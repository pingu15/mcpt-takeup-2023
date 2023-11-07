#include <bits/stdc++.h>
using namespace std;
int n,q; vector<int> v;
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; v.push_back(x);
    }
    // sort vector
    sort(v.begin(),v.end());
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        // built-in binary search
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
        cout << idx << "\n";
    }
}
