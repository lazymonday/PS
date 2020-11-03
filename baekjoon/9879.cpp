#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int INF = 1e9;
typedef long long ll;

int row, col;
int grid[MAX + 1][MAX + 1];
int wp[MAX + 1][MAX + 1];

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
int visited[MAX + 1][MAX + 1];

int bfs(int sr, int sc, int elevation) {

    memset(visited, 0, sizeof visited);
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (wp[r][c]) ++ret;

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;
            if (abs(grid[nr][nc] - grid[r][c]) > elevation) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            cin >> grid[r][c];
        }
    }

    int sr, sc;
    int numOfwp = 0;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            cin >> wp[r][c];
            if (wp[r][c]) {
                sr = r, sc = c;
                numOfwp++;
            }
        }
    }

    int lo = 0;
    int hi = 1e9;

    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        int ret = bfs(sr, sc, x);
        if (ret < numOfwp) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    cout << lo;

    return 0;
}
