#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 32000;
int n, m;

vector<int> adj[MAX + 1];
bool visited[MAX + 1];

void dfs(int u, vector<int> &orders) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {
        int next = adj[u][i];
        if (visited[next]) continue;
        dfs(next, orders);
    }

    orders.push_back(u);
}

void solve() {
    vector<int> orders;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        dfs(i, orders);
    }

    for (int j = orders.size() - 1; j >= 0; --j) {
        cout << orders[j] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    solve();
    return 0;
}
