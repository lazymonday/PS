#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int MAX_SQUARED = MAX * MAX;
const int INF = 1e9;
typedef long long ll;

struct Node {
    int root;
    int cnt;
    int startCnt;

    Node() : root(-1), cnt(1), startCnt(0) {}
};

Node nodes[MAX_SQUARED + 1];

int uf_find(int p) {
    if (nodes[p].root == -1) return p;
    return nodes[p].root = uf_find(nodes[p].root);
}

bool uf_union(int p, int q) {
    p = uf_find(p);
    q = uf_find(q);
    if (p == q) return false;

    nodes[q].root = p;
    nodes[p].cnt += nodes[q].cnt;
    nodes[p].startCnt += nodes[q].startCnt;

    return true;
}

int uf_cnt(int p) {
    return nodes[uf_find(p)].cnt;
}

int M, N, T;
int course[MAX + 1][MAX + 1];

struct Edge {
    int u, v, cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> T;

    for (int r = 0; r < M; ++r)
        for (int c = 0; c < N; ++c)
            cin >> course[r][c];

    vector<Edge> edges;

    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            int idx = r * N + c;
            cin >> nodes[idx].startCnt;
            if (r + 1 < M)
                edges.push_back({idx, (r + 1) * N + c, abs(course[r][c] - course[r + 1][c])});
            if (c + 1 < N)
                edges.push_back({idx, idx + 1, abs(course[r][c] - course[r][c + 1])});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge & lhs, const Edge & rhs) {
        return lhs.cost < rhs.cost;
    });

    ll ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        if (uf_union(edges[i].u, edges[i].v)) {
            int p = uf_find(edges[i].u);
            if (uf_cnt(p) >= T) {

                ans += 1ll * nodes[p].startCnt * edges[i].cost;
                nodes[p].startCnt = 0;
            }
        }
    }

    cout << ans;
    return 0;
}