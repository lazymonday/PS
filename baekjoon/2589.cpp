#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int row, col;
int a[51][51];
int visited[51][51];
int depth[51][51];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int bfs(int sr, int sc) {

    if (a[sr][sc] == 0 || visited[sr][sc]) {
        return 0;
    }

    int maxD = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    depth[sr][sc] = 0;
    visited[sr][sc] = 1;
    while (!q.empty()) {
        auto& x = q.front();
        int r = x.first;
        int c = x.second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                continue;
            }

            if (visited[nr][nc] || a[nr][nc] == 0) continue;

            q.push({nr, nc});
            visited[nr][nc] = 1;
            depth[nr][nc] = depth[r][c] + 1;
            maxD = max(maxD, depth[nr][nc]);
        }
    }

    return maxD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            char k;
            cin >> k;
            a[i][j] = (k == 'W' ? 0 : 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (a[i][j] == 1) {
                ans = max(ans, bfs(i, j));
                memset(visited, 0, sizeof visited);
                memset(depth, 0, sizeof depth);
            }
        }
    }

    cout << ans;

    return 0;
}
