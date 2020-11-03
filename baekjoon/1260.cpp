#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1e3;
const int INF = 2e9;
typedef long long ll;

vector<int> adj[MAX + 1];
bool visited[MAX + 1];

void dfs(int u) {

    if (visited[u]) return;
    visited[u] = 1;

    cout << u << " ";

    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        dfs(v);
    }
}

void bfs(int u) {

    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << u << " ";

        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i];
            if (!visited[v]) q.push(v);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i < n; ++i)
    {
        if (adj[i].size()) {
            sort(adj[i].begin(), adj[i].end());
        }
    }

    dfs(v);
    cout << "\n";
    memset(visited, false, sizeof visited);
    bfs(v);

    return 0;
}

