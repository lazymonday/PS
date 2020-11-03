#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
const int INF = 1e9;
typedef long long ll;


int cases, n;
int row, col;
int grid[MAX + 2][MAX + 2];
int grid2[MAX + 2][MAX + 2];
bool visited[MAX + 2][MAX + 2];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

bool dfs(int r, int c, int& hi, bool coloring = false) {

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr > row + 1 || nc < 0 || nc > col + 1 || visited[nr][nc]) continue;

        if (grid[nr][nc] == 0) {
            return false;
        } else if (grid[r][c] < grid[nr][nc]) {
            if (!coloring) hi = min(hi, grid[nr][nc]);
            continue;
        }

        if (!dfs(nr, nc, hi, coloring)) {
            return false;
        }
    }

    if (coloring) {
        grid[r][c] = max(hi, grid[r][c]);
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> cases;
    for (int k = 1; k <= cases; ++k) {
        cin >> row >> col;

        memset(grid, 0, sizeof grid);
        for (int i = 1; i <= row; ++i)
            for (int j = 1; j <= col; ++j) {
                cin >> grid[i][j];
            }

        memcpy(grid2, grid, sizeof grid);

        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                memset(visited, false, sizeof visited);
                int hi = INF;
                if (dfs(i, j, hi)) {
                    memset(visited, false, sizeof visited);
                    dfs(i, j, hi, true);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                ans += grid[i][j] - grid2[i][j];
            }
        }

        cout << "Case #" << k << ": " << ans << "\n";
    }

    return 0;
}
