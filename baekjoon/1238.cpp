#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1e4;
const int INF = 2e9;
typedef long long ll;

int n, m, x;
vector<pair<int, int>> fedges[MAX + 1];
vector<pair<int, int>> redges[MAX + 1];

void dijkstra(int start, vector<int>& dist, const vector<pair<int, int>>* edges) {

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

    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        fedges[u].push_back({v, cost});
        redges[v].push_back({u, cost});
    }

    vector<int> totalDist(n + 1, 0);
    vector<int> fdist(n + 1, INF);
    vector<int> rdist(n + 1, INF);
    dijkstra(x, fdist, fedges);
    dijkstra(x, rdist, redges);

    for (int i = 0; i <= n; ++i)
    {
        totalDist[i] = fdist[i] + rdist[i];
    }

    cout << *max_element(totalDist.begin(), totalDist.end());

    return 0;
}
