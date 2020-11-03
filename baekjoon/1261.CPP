#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
const int INF = 2e9;
typedef long long ll;

int row, col;
char a[MAX + 2][MAX + 2];
int dr[] = { -1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int dist[10001];

vector<pair<int, int>> edges[10001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    memset(dist, 63, sizeof dist);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto here = pq.top().second;
        auto cost = -pq.top().first;

        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < edges[here].size(); ++i)
        {
            int to = edges[here][i].first;
            int nc = edges[here][i].second;

            if (dist[to] > dist[here] + nc) {
                dist[to] = dist[here] + nc;
                pq.push({ -dist[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> col >> row;
    for (int i = 0; i < row; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            a[i][j] -= '0';
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;

                int cost = (a[nr][nc] == 1 ? 1 : 0);
                edges[i * col + j].push_back({nr * col + nc, cost});
            }
        }
    }

    dijkstra(0);

    cout << dist[col * row - 1];


    return 0;
}
