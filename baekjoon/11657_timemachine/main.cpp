#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int INF = 987654321;
int HALF_INF = INF / 2;

vector<vector<pair<int, int>>> edges;   // weight, v

vector<int> find(int u) {   // u is start vertex

    int V = n;
    vector<int> dist(V + 1, INF);

    dist[u] = 0;
    bool updated = false;
    for (int j = 0; j < V; ++j) {
        updated = false;
        for (int i = 1; i <= V; ++i) {
            for (int k = 0; k < edges[i].size(); ++k) {
                int cost = edges[i][k].first;
                int v = edges[i][k].second;

                if (dist[i] != INF && dist[v] > dist[i] + cost) {
                    dist[v] = dist[i] + cost;
                    updated = true;
                }
            }
        }

        if (!updated) {
            break;
        }
    }

    if (updated) {
        dist.clear();
    }

    return dist;
}

int main() {

    cin >> n >> m;

    edges.resize(n + 1);

    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
    }

    auto ret = find(1);
    if (ret.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i < ret.size(); ++i) {
            cout << (ret[i] > HALF_INF ? -1 : ret[i]) << endl;
        }
    }

    return 0;
}
