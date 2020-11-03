#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

int n;
string cowart[MAX + 3];
int seen[MAX + 3][MAX + 3];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

void bfs(int sr, int sc, bool rbsame) {

    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        auto r = q.front().first;
        auto c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || seen[nr][nc]) continue;

            if (cowart[sr][sc] == cowart[nr][nc] ||
                    (rbsame && ((cowart[sr][sc] == 'R' && cowart[nr][nc] == 'G') ||
                               (cowart[sr][sc] == 'G' && cowart[nr][nc] == 'R')))) {
                q.push({nr, nc});
                seen[nr][nc] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cowart[i];
    }

    int human = 0, cow = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!seen[i][j]) {
                bfs(i, j, false);
                human++;
            }
        }
    }

    memset(seen, 0, sizeof seen);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!seen[i][j]) {
                bfs(i, j, true);
                cow++;
            }
        }
    }

    cout << human << " " << cow;

    return 0;
}
