#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int INF = 1e9;
typedef long long ll;

int row, col;
char a[MAX + 2][MAX + 2];
int dr[] = { -1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int dist[MAX * MAX + 1];

void dijkstra(int start) {
    priority_queue<pair<int, pair<int, bool>>> pq;
    memset(dist, 63, sizeof dist);
    dist[start] = 0;
    pq.push({0, {start, false}});

    while (!pq.empty()) {
        auto cost = -pq.top().first;
        auto here = pq.top().second.first;
        bool smashed = pq.top().second.second;

        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < 4; ++i)
        {
            int nr = here / col + dr[i];
            int nc = here % col + dc[i];

            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            if (smashed && a[nr][nc] == 1) continue;

            int to = nr * col + nc;
            int w = 1;
            if (dist[to] >= dist[here] + w) {
                dist[to] = dist[here] + w;
                pq.push({ -dist[to], {to, (smashed || a[nr][nc] == 1)}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> row >> col;
    for (int i = 0; i < row; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            a[i][j] -= '0';
        }
    }

    dijkstra(0);

    if (dist[col * row - 1] > INF) {
        cout << -1;
    } else {
        cout << dist[col * row - 1] + 1;
    }

    return 0;
}
