// Author: Max Sun

#include <bits/stdc++.h>
using namespace std;

int N;
int dist[1000][1000];

const pair<int, int> nxt[] = {
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
}; //all possible knight moves

int main() {
    cin >> N;
    int hx, hy, sx, sy;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == 'H') {
                hx = i;
                hy = j;
            }
            if (c == 'S') {
                sx = i;
                sy = j;
            }
            dist[i][j] = INT32_MAX; // default distance is infinity
        }
    }
    queue<pair<int, int>> q;
    q.push({hx, hy});
    dist[hx][hy] = 0;
    while (!q.empty()) { // bfs algorithm
        auto [x, y] = q.front();
        q.pop();
        if (x == sx && y == sy) // check if reached store
            break;
        for (auto [dx, dy] : nxt) { // all possible next moves
            int newx = x + dx, newy = y + dy;
            if (newx < 0 || newy < 0 || newx >= N || newy >= N) // check for out of bounds
                continue;
            if (dist[x][y] + 1 < dist[newx][newy]) { // check if new distance is less than old distance
                dist[newx][newy] = dist[x][y] + 1;
                q.push({newx, newy});
            }
        }
    }
    cout << dist[sx][sy]*3+abs(sx-hx)+abs(sy-hy) << "\n"; // dist[sx][sy]*3 for each knight move goes through 3 squares
}