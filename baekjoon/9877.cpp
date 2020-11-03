#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int INF = 1e9;
typedef long long ll;


int row, col, t;
int grid[MAX + 1][MAX + 1];
int pt[MAX + 1][MAX + 1];
int ans[MAX + 1][MAX + 1];
int cand[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

bool bfs(int sr, int sc, int maxDepth, int maxElevation) {

    memset(visited, 0, sizeof visited);
    memset(cand, 0, sizeof cand);

    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    int curLength = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();
        curLength++;

        if(curLength >= maxDepth) {
            cand[r][c] = maxElevation;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;

            if (abs(grid[r][c] - grid[nr][nc]) > maxElevation) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return curLength >= maxDepth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("skilevel/2.in", "r", stdin);

    cin >> row >> col >> t;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            cin >> grid[r][c];
        }
    }

    memset(ans, 0x3f, sizeof ans);

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            cin >> pt[r][c];
            if (pt[r][c]) {
                if (ans[r][c] != 0x3f3f3f3f) continue;
                int lo = 0;
                int hi = 1e9 + 1;

                while (lo < hi) {
                    int x = lo + (hi - lo) / 2;

                    if (!bfs(r, c, t, x)) {
                        lo = x + 1;
                    } else {
                        hi = x;
                    }
                }

                ans[r][c] = lo;
            }
        }
    }

    ll answer = 0;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (pt[r][c]) {
                answer += ans[r][c];
            }
        }
    }

    cout << answer;
    return 0;
}
