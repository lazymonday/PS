#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
const int INF = 1e9;
typedef long long ll;

int n, m;

typedef vector<pair<int, int>> Switch;
int lit[MAX][MAX];
int seen[MAX][MAX];
Switch sw[MAX][MAX];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        sw[r][c].push_back({a, b});
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    lit[1][1] = 1;

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        seen[pos.first][pos.second] = true;

        for (auto x : sw[pos.first][pos.second]) {
            if (!lit[x.first][x.second]) {
                lit[x.first][x.second] = 1;
                if (seen[x.first][x.second]) {
                    q.push(x);
                }
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int nr = pos.first + dr[i];
            int nc = pos.second + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > n || seen[nr][nc]) continue;

            seen[nr][nc] = true;

            if (lit[nr][nc]) {
                q.push({nr, nc});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (lit[i][j]) ans++;
        }
    }

    cout << ans;

    return 0;
}
