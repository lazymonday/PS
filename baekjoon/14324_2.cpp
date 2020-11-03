#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
const int INF = 1e9;
typedef long long ll;

int cases, row, col;
int grid[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

struct Node {
    int r, c, h;
    bool operator<(const Node& o) const {
        return h > o.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> cases;
    for (int k = 1; k <= cases; ++k) {
        cin >> row >> col;

        memset(visited, 0, sizeof visited);
        priority_queue<Node> pq;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cin >> grid[i][j];
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    pq.push({i, j, grid[i][j]});
                    visited[i][j] = true;
                }
            }
        }

        int ans = 0;
        while (!pq.empty()) {
            auto& top = pq.top();
            int r = top.r;
            int c = top.c;
            int h = top.h;
            pq.pop();

            visited[r][c] = true;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;

                if (grid[nr][nc] < h) {
                    ans += h - grid[nr][nc];
                    grid[nr][nc] = h;
                }

                pq.push({nr, nc, grid[nr][nc]});
            }
        }

        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
