#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;
const int INF = 1e9;
typedef long long ll;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct Node {
    int size, weight;
    Node() : size(1), weight(0) {}
} nodes[MAX + 1];

int n, m, q;
Edge edges[MAX + 1];
vector<Edge> adj[MAX + 1];

int root[MAX + 1];
int rank[MAX + 1];

int uf_find(int p) {
    if (root[p] == -1) return p;
    return root[p] = uf_find(root[p]);
}

int parent[MAX + 1][21];
int h[MAX + 1];

int lca(int p, int q) {
    if (h[p] > h[q]) {
        swap(p, q);
    }

    for (int i = 20; i >= 0; --i)
    {
        if (h[q] - h[p] >= (1 << i))
            q = parent[q][i];
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

void dfs(int start, int p) {
    for (auto next : adj[start]) {
        if (next.v == p) continue;
        parent[next.v][0] = start;
        h[next.v] = h[start] + 1;
        dfs(next.v, start);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--, edges[i].v--;
    }

    sort(edges, edges + m);

    memset(root, -1, sizeof root);

    for (int i = 0; i < m; ++i)
    {
        int u = uf_find(edges[i].u), v = uf_find(edges[i].v);
        if (u != v) {
            adj[i + n].push_back({i + n, u, edges[i].w});
            adj[i + n].push_back({i + n, v, edges[i].w});
            nodes[i + n].size = nodes[u].size + nodes[v].size;
            nodes[i + n].weight = edges[i].w;

            int mergeTo = uf_find(i + n);
            root[u] = mergeTo;
            root[v] = mergeTo;
        }
    }

    for (int i = n + m - 1 ; i >= 0; --i) {
        if (!h[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 0; j < n + m; ++j) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    cin >> q;
    int start, end;
    for (int i = 0; i < q; ++i)
    {
        cin >> start >> end;
        --start, --end;
        if (uf_find(start) == uf_find(end)) {
            int idx = lca(start, end);
            cout << nodes[idx].weight << " " << nodes[idx].size << "\n";
        } else {
            cout << "-1\n";
        }

    }


    return 0;
}
