#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

int n;
vector<int> edges[MAX + 1];
bool visited[MAX + 1];

void dfs(int u) {
    visited[u] = true;

    for (auto next : edges[u]) {
        if (visited[next]) continue;
        dfs(next);
    }
}

bool check() {
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) return false;
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        edges[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; ++i)
    {
        memset(visited, 0, sizeof visited);
        dfs(i);
        if (check()) {
            cout << i + 1;
            return 0;
        }
    }


    cout << -1;


    return 0;
}
