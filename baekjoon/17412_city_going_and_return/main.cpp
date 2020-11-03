#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 400;
const int INF = 1e9;

struct edge {
    int v, cap, f;
    edge *rev;

    bool residualFlow() {
        return cap > f;
    }

    void flow(int f_) {
        f += f_;
        rev->f -= f_;
    }
};

vector<edge *> adj[MAX + 1];
int n, m;

int main() {

    cin >> n >> m;

    int src = 1, sink = 2;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        int cap = 1;
        edge *e = new edge{v, cap, 0};
        edge *r = new edge{u, 0, 0};
        e->rev = r;
        r->rev = e;

        adj[u].push_back(e);
        adj[v].push_back(r);
    }

    int totalFlow = 0;

    while (true) {
        int parent[401];
        edge *path[401];
        memset(parent, -1, sizeof parent);
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < adj[u].size(); ++i) {
                auto e = adj[u][i];
                if (e && parent[e->v] == -1 && e->residualFlow()) {
                    parent[e->v] = u;
                    path[e->v] = e;
                    q.push(e->v);
                    if (e->v == sink) break;
                }
            }
        }

        if (parent[sink] == -1) break;

        for (int p = sink; p != src; p = parent[p]) {
            path[p]->flow(1);
        }

        totalFlow++;
    }


    cout << totalFlow << "\n";

    return 0;
}
