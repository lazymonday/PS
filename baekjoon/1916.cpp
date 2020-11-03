#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n, m;
vector<pair<int, int>> edges[MAX + 1];
int dist[1001];

void dijkstra(int start) {

    memset(dist, 63, sizeof dist);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        auto cost = pq.top().first;
        auto here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < edges[here].size(); ++i)
        {
            int next = edges[here][i].first;
            int c = edges[here][i].second;

            if (dist[next] > dist[here] + c) {
                dist[next] = dist[here] + c;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[u].push_back({v, cost});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << dist[end];

    return 0;
}
