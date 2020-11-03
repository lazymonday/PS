#include <iostream>
#include <vector>

using namespace std;

int n, m;

const int MAX = 1001;

vector<int> adj[MAX];
vector<int> matchedA;
vector<int> matchedB;

bool dfs(int u, vector<bool> &visited) {
    if (visited[u]) {
        return false;
    }

    visited[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (matchedB[v] == -1 || dfs(matchedB[v], visited)) {
            matchedB[v] = u;
            matchedA[u] = v;
            return true;
        }
    }

    return false;
}

int solve() {
    int flow = 0;
    for (int i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1, false);
        if (dfs(i, visited)) {
            ++flow;
        }
    }

    return flow;
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;

        for (int j = 0; j < c; ++j) {
            int to;
            cin >> to;
            adj[i].push_back(to);
        }
    }

    matchedA.resize(n + 1, -1);
    matchedB.resize(m + 1, -1);

    cout << solve() << endl;

    return 0;
}
