#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int R, C;
string grid[22];
bool seen[22][22];
bool alpha[26];
unordered_map<int, bool> dp[22][22];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int solve(int r, int c, int subset, int cand) {

    if (dp[r][c].find(subset) != dp[r][c].end()) return 0;

    dp[r][c].insert({subset, true});
    int pos = grid[r][c];
    alpha[pos] = true;
    seen[r][c] = true;

    int ret = cand;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C || seen[nr][nc]) continue;

        int nextPos = grid[nr][nc];
        if (!alpha[nextPos]) {
            ret = max(solve(nr, nc, subset | 1 << nextPos, cand + 1), ret);
        }
    }

    alpha[pos] = false;
    seen[r][c] = false;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (int j = 0; j < C; ++j) grid[i][j] -= 'A';
    }

    cout << solve(0, 0, 1 << grid[0][0], 1);

    return 0;
}
