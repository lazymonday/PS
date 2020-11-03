#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
string icy[MAX + 5];
bool visited[MAX + 5][MAX + 5];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

pair<int, int> bfs(int r, int c) {
    int peri = 0;
    int area = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        auto top = q.front();
        int row = top.first, col = top.second;
        q.pop();
        area++;

        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || icy[nr][nc] == '.') {
                peri++;
                continue;
            }

            if (visited[nr][nc]) continue;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    return {area, peri};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> icy[i];

    int area = 0, peri = INF;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j] || icy[i][j] != '#') continue;
            auto ret = bfs(i, j);
            if (area < ret.first) {
                area = ret.first;
                peri = ret.second;
            } else if (area == ret.first) {
                peri = min(peri, ret.second);
            }
        }
    }

    cout << area << " " << peri;
    return 0;
}
