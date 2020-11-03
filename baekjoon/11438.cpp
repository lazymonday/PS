#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n, m;
vector<int> edges[MAX + 1];
int depth[MAX + 1];
int parent[MAX + 1][21];

void dfs(int u, int from) {
    parent[u][0] = from;
    depth[u] = depth[from] + 1;

    for (auto next : edges[u]) {
        if (next == from) continue;
        dfs(next, u);
    }
}

void prepare() {

    dfs(1, 0);

    for (int j = 1; j <= 20; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int p, int q) {

    if (depth[p] > depth[q]) {
        swap(p, q);
    }

    for (int i = 20; i >= 0; --i)
    {
        if (depth[q] - depth[p] >= (1 << i)) {
            q = parent[q][i];
        }
    }

    if (p == q) return p;

    for (int i = 20; i >= 0; --i)
    {
        if (parent[p][i] != parent[q][i]) {
            p = parent[p][i];
            q = parent[q][i];
        }
    }

    return parent[p][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int u, v;
    for (int i = 0; i < n - 1; ++i) // # of edges = n-1
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    prepare();

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}
