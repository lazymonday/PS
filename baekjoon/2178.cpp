#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int map[101][101];
bool visited[101][101];
int dist[101][101];

int n, m;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};


void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        auto here = q.front();
        q.pop();

        visited[here.first][here.second] = true;

        for (int i = 0; i < 4; ++i)
        {
            int nr = here.first + dr[i];
            int nc = here.second + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m ||
                    map[nr][nc] == 0 || visited[nr][nc]) {
                continue;
            }

            if (dist[nr][nc] > dist[here.first][here.second] + 1) {
                q.push({nr, nc});
                dist[nr][nc] = dist[here.first][here.second] + 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            map[i][j] = (s[j] == '1' ? 1 : 0);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dist[i][j] = INF;
        }
    }

    bfs();

    cout << dist[n - 1][m - 1];

    return 0;
}
