#include <bits/stdc++.h>

using namespace std;

const int MAX_COL = 500;
const int MAX_ROW = 1e4;
const int INF = 1e9;
typedef long long ll;

int row, col;
char grid[MAX_ROW][MAX_COL];
int dr[] = { -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("plinovod/plinovod.in.3", "r", stdin);

    cin >> row >> col;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin >> grid[i][j];

    for (int r = 0; r < row; ++r) grid[r][0] = 1;

    int ans = row;
    for (int c = 0; c < col - 1; ++c)
    {
        int nc = c + 1;
        int cand = 0;
        for (int r = 0; r < row; ++r)
        {
            if (grid[r][c] != 1) continue;
            for (int k = 0; k < 3; ++k)
            {
                int nr = r + dr[k];
                if (nr < 0 || nr >= row || grid[nr][nc] == 1) continue;
                if (grid[nr][nc] != 'x') {
                    cand++;
                    grid[nr][nc] = 1;
                }
            }
        }
        ans = min(ans, cand);
    }

    return 0;
}
