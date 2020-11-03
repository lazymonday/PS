#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int NODE_MAX = 5e4;
const int INF = 1e9;
typedef long long ll;


int n, m;

const int Red = 1;
const int Black = 2;

vector<int> edges[MAX + 1];
int color[NODE_MAX + 1];
int cnt[3];

inline int nextColor(int color) {
    return (color == Red ? Black : Red);
}

bool dfs(int u, int c) {

    if (color[u]) return true;

    color[u] = c;
    cnt[c]++;

    int nc = nextColor(c);
    for (auto v : edges[u]) {
        if (!dfs(v, nc) || color[v] == c) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!dfs(i, Red)) {
            cout << -1;
            return 0;
        }
        ans += max(cnt[Red], cnt[Black]);
        cnt[Red] = cnt[Black] = 0;
    }

    cout << ans;

    return 0;
}
