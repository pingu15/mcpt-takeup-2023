#include <bits/stdc++.h>
using namespace std;
int n,m; set<int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n+m; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    // answer is the number of values that do not go into the set 
    cout << n+m-s.size() << "\n";
}
