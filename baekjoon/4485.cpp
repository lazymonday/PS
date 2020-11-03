#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 125;
const int INF = 2e9;
typedef long long ll;

int n;
int a[MAX + 1][MAX + 1];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
int dist[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int idx = 1;
    while (true) {

        cin >> n;
        if (!n) break;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
            }
        }

        memset(dist, 63, sizeof dist);
        priority_queue<pair<int, pair<int, int>>> q;

        q.push({0, {0, 0}});
        dist[0][0] = a[0][0];

        while (!q.empty()) {
            auto distance = -q.top().first;
            auto r = q.top().second.first;
            auto c = q.top().second.second;
            q.pop();

            if (dist[r][c] < distance) continue;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                if (dist[r][c] + a[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + a[nr][nc];
                    q.push({ -dist[nr][nc], {nr, nc}});
                }
            }
        }

        cout << "Problem " << idx++ << ": " << dist[n - 1][n - 1] << "\n";
    }

    return 0;
}
