#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<int,string>> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        string s; int x;
        cin >> s >> x;
        v.push_back({x,s}); // storing ripeness and name
    }
    // sorting vector
    sort(v.begin(),v.end(),greater<pair<int,string>>());
    for (int i = 0; i < q; ++i){
        int n; cin >> n; n--;
        // printing name of lychee
        cout << v[n].second << "\n";
    }
}
