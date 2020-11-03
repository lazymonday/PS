#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000;
const int INF = 1e9;
typedef long long ll;

int n, q;

vector<pair<int, int>> edges[MAX + 1];

int visited[MAX + 1];

int bfs(int start, int k) {

    memset(visited, 0, sizeof visited);

    queue<pair<int, int>> q;
    q.push({INF, start});

    int ans = 0;
    while (!q.empty()) {
        auto here = q.front();

        if (here.first >= k) ans++;
        visited[here.second] = true;
        q.pop();

        for (auto next : edges[here.second]) {
            if (visited[next.first]) continue;
            q.push({min(here.first, next.second), next.first});
        }
    }

    return (ans > 0 ? ans -1 : ans);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    int u, v, w;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }


    int start, k;
    for (int i = 0; i < q; ++i)
    {
        cin >> k >> start;
        cout << bfs(start, k) << "\n";
    }

    return 0;
}
