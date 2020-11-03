#include <bits/stdc++.h>

using namespace std;

const int MAX = 800;
const int INF = 2e9;
typedef long long ll;

int n, m;
vector<pair<int, int>> edges[MAX + 1];
int dist[MAX + 1];

void dijkstra(int start) {

    memset(dist, 63, sizeof dist);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        auto cost = -pq.top().first;
        auto here = pq.top().second;

        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < edges[here].size(); ++i)
        {
            int there = edges[here][i].first;
            int co = edges[here][i].second;

            if (dist[there] > dist[here] + co) {
                dist[there] = dist[here] + co;
                pq.push({ -dist[there], there});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    ll ans1 = 0, ans2 = 0;
    dijkstra(1);
    ans1 += dist[v1];
    ans2 += dist[v2];
    dijkstra(v1);
    ans1 += dist[v2];
    ans2 += dist[n];
    dijkstra(v2);
    ans1 += dist[n];
    ans2 += dist[v1];

    ll ans = min(ans1, ans2);
    if (ans > 1e9) {
        ans = -1;
    }
    cout << ans;
    return 0;
}
