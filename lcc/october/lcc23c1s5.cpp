// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> arr;

bool isPossible(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = N-1; i >= N-n; i--) {
        pq.push({arr[i], arr[i]});
    }
    int day = 1;
    for(int i = 0; i < K; i++) { // simulate all K days
        for(int j = 0; j < 3; j++) { // feed 3 most hungry children
            pair<int, int> p = pq.top();
            pq.pop();
            pq.push({p.first+p.second, p.second});
        }
        if(pq.top().first <= day) return false; // if any kid's hunger level is 0, Alice cannot keep all children alive
        day++;
    }
    return true;
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int lo = 0, hi = N;
    while(lo < hi) { // binary search for maximum number of children
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(isPossible(mid)) { // is it possible to keep <mid> children alive?
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo << endl;
}