#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
const int INF = 1e9;
typedef long long ll;

int n, m;
int puz[MAX + 5][MAX + 5];
int seen[MAX + 5][MAX + 5];
const int Horizontal = 1 << 0;
const int Vertical = 1 << 1;

int dfs(int r, int c, bool isHoriz) {

    if (seen[r][c] & (isHoriz ? Horizontal : Vertical)) {
        return 1;
    }

    int dist = 1;
    seen[r][c] |= (isHoriz ? Horizontal : Vertical);

    if (isHoriz) {
        int nc = c + 1;
        if (nc < m && (seen[r][nc] & Horizontal) == 0 && puz[r][nc] == 0) {
            dist += dfs(r, nc, isHoriz);
        }
    } else {
        int nr = r + 1;
        if (nr < n && (seen[nr][c] & Vertical) == 0 && puz[nr][c] == 0) {
            dist += dfs(nr, c, isHoriz);
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                puz[i][j] = 1;
            }
        }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (puz[i][j]) continue;
            int hd = 0, vd = 0;
            if (((j - 1 < 0 || puz[i][j - 1] == 1) && (hd = dfs(i, j, true)) >= 3) ||
                    ((i - 1 < 0 || puz[i - 1][j] == 1) && (vd = dfs(i, j, false)) >= 3)) {
                ans.push_back({i+1, j+1});
            }
        }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
