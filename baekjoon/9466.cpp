#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int adj[MAX + 1];
bool visited[MAX + 1];
bool record[MAX + 1];
int depth[MAX + 1];

int dfs(int u, int dep) {
    if (visited[u]) return 0;

    int ret = 0;
    int v = adj[u];
    if (v == u) return 0;

    visited[u] = true;
    record[u] = true;
    depth[u] = dep;

    if (!visited[v]) {
        ret = dfs(v, dep + 1);
    } else if (record[v]) {
        ret = dep - depth[v] + 1;
    }

    record[u] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int total = n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> adj[i];
            if (adj[i] == i) total--;
        }

        for (int i = 1; i <= n; ++i)
        {
            int ret = dfs(i, 0);
            if (ret) total -= ret;
        }

        cout << total << "\n";

        memset(adj, 0, sizeof adj);
        memset(visited, 0, sizeof visited);
        memset(depth, 0, sizeof depth);
        memset(record, 0, sizeof record);
    }

    return 0;
}
