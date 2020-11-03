#include <bits/stdc++.h>

using namespace std;

const int NODE_MAX = 1000;
const int INF = 1e9;
typedef long long ll;

int n, p, k;
int dist[NODE_MAX + 1];
vector<pair<int, int>> edges[NODE_MAX + 1];

bool dijkstra(int start, int threshold) {

    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int here = pq.top().second;
        int w = -pq.top().first;
        pq.pop();

        if (dist[here] < w) continue;

        for (int i = 0; i < edges[here].size(); ++i)
        {
            int there = edges[here][i].first;
            int cost = w + (edges[here][i].second > threshold);

            if (dist[there] > cost) {
                dist[there] = cost;
                pq.push({ -cost, there});
            }
        }
    }

    return dist[n] <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> k;

    int u, v, cost;
    for (int i = 1; i <= p; ++i)
    {
        cin >> u >> v >> cost;
        edges[u].push_back({v, cost});
        edges[v].push_back({u, cost});
    }

    int ans = -1;
    int lo = 0;
    int hi = 1e6 + 1;
    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        bool ok = [&]() {
            memset(dist, 0x3f, sizeof dist);
            return dijkstra(1, x);
        }();

        if (ok) {
            ans = hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << ans;
    return 0;
}
