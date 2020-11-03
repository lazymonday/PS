#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 200;
int n, m;
vector<int> adj[MAX + 1];

int matchedA[MAX + 1];
int matchedB[MAX + 1];
int visited[MAX + 1];

bool dfs(int u) {
    if (visited[u])
        return false;

    visited[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (matchedB[v] == -1 || dfs(matchedB[v])) {
            matchedB[v] = u;
            matchedA[u] = v;
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int shed;
        for (int j = 0; j < k; ++j) {
            cin >> shed;
            adj[i].push_back(shed);
        }
    }

    memset(matchedA, -1, sizeof matchedA);
    memset(matchedB, -1, sizeof matchedB);
    int flow = 0;
    for (int l = 0; l < n; ++l) {
        memset(visited, 0, sizeof visited);
        if (dfs(l)) ++flow;
    }

    cout << flow;

    return 0;
}
