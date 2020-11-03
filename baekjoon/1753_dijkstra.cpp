#include <iostream>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int V, E, S;
const int INF = 987654321;

vector<vector<pair<int, int>>> edges;   // edge, weight

vector<int> dijkstra(int s) {
    vector<int> dist(V + 1, INF);
    vector<bool> visited(V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (visited[here]) {
            continue;
        }
        visited[here] = true;

        if (dist[here] < cost) {
            continue;
        }

        for (int i = 0; i < edges[here].size(); ++i) {
            int there = edges[here][i].first;
            int c = edges[here][i].second;

            if (dist[there] > dist[here] + c) {
                dist[there] = dist[here] + c;
                pq.push({dist[there], there});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E >> S;

    edges.resize(V + 1);
    int u, v, w;
    for (int i = 1; i <= E; ++i) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }

    auto ret = dijkstra(S);
    for (int j = 1; j < ret.size(); ++j) {
        if (ret[j] == INF) {
            cout << "INF\n";
        } else {
            cout << ret[j] << "\n";
        }
    }

    return 0;
}
