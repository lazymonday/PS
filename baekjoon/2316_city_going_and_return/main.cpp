#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 400 * 2;
const int INF = 1e9;

struct edge {
    int v, cap, f;
    edge *rev;

    inline int residualFlow() {
        return cap - f;
    }

    inline void flow(int f_) {
        f += f_;
        rev->f -= f_;
    }
};

vector<edge *> adj[MAX + 2];
int n, m;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int j = 2; j < n; ++j) {
        edge *e = new edge{j * 2 + 1, 1, 0};
        edge *r = new edge{j * 2, 0, 0};
        e->rev = r;
        r->rev = e;
        adj[j * 2].push_back(e);
        adj[j * 2 + 1].push_back(r);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        edge *e = new edge{2 * v, 1, 0};
        edge *r = new edge{2 * u + 1, 0, 0};
        e->rev = r;
        r->rev = e;

        adj[2 * u + 1].push_back(e);
        adj[2 * v].push_back(r);

        e = new edge{2 * u, 1, 0};
        r = new edge{2 * v + 1, 0, 0};
        e->rev = r;
        r->rev = e;

        adj[2 * v + 1].push_back(e);
        adj[2 * u].push_back(r);
    }

    int totalFlow = 0;
    int src = 1, sink = 2;

    while (true) {
        int parent[MAX + 2];
        edge *path[MAX + 2];
        memset(parent, -1, sizeof parent);
        queue<int> q;
        q.push(src);

        while (!q.empty() && parent[sink] == -1) {
            auto here = q.front();
            q.pop();

            for (auto e : adj[here]) {
                int next = e->v;
                if (parent[next] == -1 && e->residualFlow() > 0) {
                    parent[next] = here;
                    path[next] = e;
                    q.push(next);
                    if (next == sink) break;
                }
            }
        }

        if (parent[sink] == -1)
            break;

        for (int p = sink; p != src; p = parent[p]) {
            path[p]->flow(1);
        }

        totalFlow++;
    }

    cout << totalFlow;

    for (int k = 0; k < n; ++k) {
        for (auto &e : adj[k]) {
            delete e;
        }
        adj[k].clear();
    }

    return 0;
}