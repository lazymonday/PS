#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int INF = 1e9;
const int MAX = 52;
int c[MAX + 1][MAX + 1];
int f[MAX + 1][MAX + 1];
int parent[MAX + 1];
vector<int> adj[MAX + 1];
int n;

inline int idx(char v) {
    return v - (v <= 'Z' ? 'A' : ('a' - 26));
}

int main() {
    cin >> n;
    char uc, vc;
    int cap;
    for (int i = 0; i < n; ++i) {
        cin >> uc >> vc >> cap;
        int u = idx(uc), v = idx(vc);
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = c[v][u] += cap;
    }

    int source = idx('A'), sink = idx('Z');
    int flow = 0;
    while (true) {
        memset(parent, -1, sizeof parent);
        queue<int> q;
        q.push(source);

        int residualCap = INF;
        while (!q.empty() && parent[sink] == -1) {
            auto here = q.front();
            q.pop();
            for (auto next : adj[here]) {
                if (c[here][next] > f[here][next] && parent[next] == -1) {
                    parent[next] = here;
                    residualCap = min(residualCap, c[here][next] - f[here][next]);
                    if (next == sink) break;
                    q.push(next);
                }
            }
        }

        if (parent[sink] == -1) break;
        if (residualCap != INF) flow += residualCap;

        for (int prev = sink; prev != source; prev = parent[prev]) {
            f[parent[prev]][prev] += residualCap;
            f[prev][parent[prev]] -= residualCap;
        }
    }

    cout << flow;
    return 0;
}
