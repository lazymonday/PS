#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int NODE_MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n, m;

struct edge {
    int u, v, cost;
};

edge edges[MAX + 1];

class UnionFind {
public:
    UnionFind(int max) {
        for (int i = 0; i <= max; ++i) {
            roots[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        int p = roots[x];
        while (p != roots[p]) {
            roots[p] = roots[roots[p]];
            p = roots[p];
        }

        return p;
    }

    void uni(int p, int q) {
        p = find(p);
        q = find(q);

        if (p == q) {
            return;
        }

        if (rank[p] < rank[q]) {
            roots[p] = q;
        } else {
            roots[q] = p;
            if (rank[p] == rank[q]) {
                rank[p]++;
            }
        }
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

private:
    int roots[NODE_MAX + 1];
    int rank[NODE_MAX + 1];
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int u, v, cost;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> cost;
        edges[i] = {u, v, cost};
    }

    sort(edges, edges + m, [](const auto & lhs, const auto & rhs) {
        return lhs.cost < rhs.cost;
    });

    UnionFind uf(n);

    int mstSize = 0;
    int totalCost = 0;
    for (int i = 0; i < m && mstSize < n - 2; ++i)
    {
        if (!uf.isConnected(edges[i].u, edges[i].v)) {
            uf.uni(edges[i].u, edges[i].v);
            mstSize++;
            totalCost += edges[i].cost;
        }
    }

    cout << totalCost;

    return 0;
}
