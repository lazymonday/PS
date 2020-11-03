#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int NodeMax = 1e4;
const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

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
    int roots[NodeMax + 1];
    int rank[NodeMax + 1];
} uf(NodeMax + 1);



int n, m;
int s, e;

struct Edge {
    int u, v, cost;
};

Edge edges[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    cin >> s >> e;

    sort(edges, edges + m, [](const Edge & a, const Edge & b) {
        return a.cost > b.cost;
    });


    for (int i = 0; i < m; ++i)
    {
        if (!uf.isConnected(edges[i].u, edges[i].v)) {
            uf.uni(edges[i].u, edges[i].v);
        }

        if (uf.isConnected(s, e)) {
            cout << edges[i].cost;
            return 0;
        }
    }

    return 0;
}
