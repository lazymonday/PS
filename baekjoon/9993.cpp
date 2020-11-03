#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n, m;
char mirror[MAX + 5][MAX + 5];

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
const int Right = 0;
const int Up = 1;
const int Left = 2;
const int Down = 3;

const int nextDir[2][4] = {
    {Up, Right, Down, Left},
    {Down, Left, Up, Right}
};

int dfs(int r, int c, int fromDir) {
    if (mirror[r][c] == 0) return 0;

    int toDir, ret = 1;
    if (mirror[r][c] == '/') {
        toDir = nextDir[0][fromDir];
    } else {
        toDir = nextDir[1][fromDir];
    }

    int nr = r + dr[toDir];
    int nc = c + dc[toDir];

    return ret += dfs(nr, nc, toDir);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mirror[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= m + 1; ++j)
        {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if (r < 0 || r > n + 1 || c < 0 || c > m + 1 || !mirror[r][c]) continue;

                    ans = max(ans, dfs(r, c, k));
                }
            }
        }
    }

    cout << ans;

    return 0;
}
