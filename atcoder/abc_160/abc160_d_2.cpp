#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 2e3;
const int INF = 2e9;
typedef long long ll;

int n, x, y;
vector<int> adj[MAX + 1];
ll ans[MAX + 1];

vector<int> dijkstra(int u) {

    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[u] = 0;
    pq.push({dist[u], u});

    while (!pq.empty()) {
        auto& x = pq.top();
        int here = x.second;
        int cost = x.first;
        pq.pop();

        // if (visited[here]) continue;
        // visited[here] = true;

        if (dist[here] < cost) {
            continue;
        }

        for (auto && there : adj[here]) {
            if (dist[there] > dist[here] + 1) {
                dist[there] = dist[here] + 1;
                pq.push({dist[there], there});
            }
        }
    }

    return dist;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x >> y;

    for (int i = 1; i < n; ++i)
    {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }
    adj[x].push_back(y);
    adj[y].push_back(x);

    vector<ll> ans(n - 1);
    for (int i = 1; i < n; ++i)
    {
        auto&& dist = dijkstra(i);
        for (int j = i + 1; j <= n; ++j)
        {
            ans[dist[j] - 1]++;
        }
    }

    for (auto && x : ans)
        cout << x << "\n";

    return 0;
}
