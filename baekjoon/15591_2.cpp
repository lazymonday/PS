#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000;
const int INF = 1e9;
typedef long long ll;

int n, q;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

struct Query {
    int k, v, index, ans;
    bool operator<(const Query& other) const {
        return k > other.k;
    }
};

Edge edges[MAX + 1];
Query queries[MAX + 1];

int cnt[MAX + 1];
int root[MAX + 1];
int union_find(int p) {
    if (root[p] == -1) return p;
    return root[p] = union_find(root[p]);
}

void union_merge(int p, int q) {
    p = union_find(p);
    q = union_find(q);

    if (p == q) return;

    cnt[q] += cnt[p];
    root[p] = q;
}

int node_count(int p) {
    return cnt[union_find(p)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i <= n; ++i) cnt[i] = 1;

    int u, v, w;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int k, node;
    for (int i = 0; i < q; ++i)
    {
        cin >> k >> node;
        queries[i] = {k, node, i, 0};
    }

    sort(edges, edges + n - 1);
    sort(queries, queries + q);

    memset(root, -1, sizeof root);

    int edgeIdx = 0;
    for (int i = 0 ; i < q; ++i) {
        while (edgeIdx < n - 1 && edges[edgeIdx].w >= queries[i].k) {
            union_merge(edges[edgeIdx].u, edges[edgeIdx].v);
            edgeIdx++;
        }

        queries[i].ans = node_count(queries[i].v) - 1;
    }

    sort(queries, queries + q, [](const Query & lhs, const Query & rhs) {
        return lhs.index < rhs.index;
    });

    for (int i = 0; i < q; ++i)
    {
        cout << queries[i].ans << "\n";
    }

    return 0;
}
