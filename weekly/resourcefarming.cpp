#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
char arr[1005][1005]; bool vis[1005][1005]; int maxv, ans, n, m;
// vector of possible moves on the grid
vector<pii> vec = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
// floodfill bfs 
int bfs(int i, int j) {
    int val = 1;
    queue<pii> q;
    q.push({i,j});
    vis[i][j] = true;
    while (!q.empty()) {
        // current position
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // different possible moves
        for (int k = 0; k < 8; k++) {
            int x2 = x+vec[k].first, y2 = y+vec[k].second;
            // check if the move is in the grid and is a resource spot
            if (!vis[x2][y2] && x2 >= 1 && x2 <= m && y2 >= 1 && y2 <= n && arr[x2][y2] == '#') {
                val++;
                
                vis[x2][y2] = true;
                q.push({x2,y2});
            }
        }
    }
    return val;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j]; 
            // to ignore all the non-resource spots
            if (arr[i][j] == '.') vis[i][j] = true;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // do bfs at non-visited resource spots
            if (!vis[i][j]) {maxv = max(maxv,bfs(i,j)); ans++;}
        }
    }
    cout << ans << " " << maxv << "\n";
}
