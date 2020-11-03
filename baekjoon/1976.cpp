#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 200;
const int INF = 2e9;
typedef long long ll;

int dist[MAX + 1];
int adj[MAX + 1][MAX + 1];
int cities[1001];
int n, m;

void solve(int s) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<bool> visited(n, false);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto here = pq.top().second;
        auto cost = pq.top().first;

        pq.pop();

        if (dist[here] < cost) continue;

        for (int to = 0; to < n; ++to)
        {
            if (!adj[here][to] || visited[to]) continue;
            if (dist[here] + 1 < dist[to]) {
                dist[to] = dist[here] + 1;
                pq.push({dist[to], to});
                visited[to] = true;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> cities[i];
        cities[i]--;
    }

    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
    }

    solve(cities[0]);

    for (int i = 0; i < m; ++i)
    {
        if (dist[cities[i]] == INF) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";


    return 0;
}
