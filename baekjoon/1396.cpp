#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

struct Edge {
    int u, v, w;
};

struct Query {
    int u, v;
    int minCost;
    int cnt;
    int lo, hi;
};

int n, m, q;
int root[MAX + 1];
int cnt[MAX + 1];
int uf_rank[MAX + 1];

void uf_init() {
    memset(root, -1, sizeof root);
    for (int i = 0; i < n; ++i) cnt[i] = 1;
}

int uf_find(int p) {
    if (root[p] == -1) return p;
    return root[p] = uf_find(root[p]);
}

bool uf_union(int p, int q) {
    p = uf_find(p);
    q = uf_find(q);

    if (p == q) return false;

    if (uf_rank[p] < uf_rank[q]) {
        root[p] = q;
        cnt[q] += cnt[p];
    } else {
        root[q] = p;
        cnt[p] += cnt[q];
        uf_rank[p]++;
    }

    return true;
}

int uf_size(int p) {
    return cnt[uf_find(p)];
}

bool uf_connected(int p, int q) {
    p = uf_find(p);
    q = uf_find(q);

    return p == q;
}

Edge edges[MAX + 1];
Query queries[MAX + 1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    sort(edges, edges + m, [](const Edge & lhs, const Edge & rhs) {
        return lhs.w < rhs.w;
    });


    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> u >> v;
        queries[i] = {u - 1, v - 1, -1, 0, 0, m};
    }


    while (true) {
        uf_init();
        vector<int> bunch[MAX + 1];

        bool done = true;
        int upper = -1;
        for (int i = 0; i < q; ++i)
        {
            if (queries[i].lo >= queries[i].hi) continue;
            int x = queries[i].lo + (queries[i].hi - queries[i].lo) / 2;
            bunch[x].push_back(i);
            upper = max(x, upper);
            done = false;
        }

        if (done) break;

        for (int i = 0; i < m && i <= upper; ++i)
        {
            int u = edges[i].u;
            int v = edges[i].v;

            uf_union(u, v);

            for (auto idx : bunch[i]) {
                if (uf_connected(queries[idx].u, queries[idx].v)) {
                    queries[idx].hi = i;
                    queries[idx].minCost = edges[i].w;
                    queries[idx].cnt = uf_size(queries[idx].u);
                } else {
                    queries[idx].lo = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < q; ++i)
    {
        cout << queries[i].minCost;
        if (queries[i].minCost != -1) {
            cout << " " << queries[i].cnt;
        }
        cout << "\n";
    }

    return 0;
}
