#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAX = 1000;
int t, n, k;

int solve() {

    cin >> n >> k;
    vector<int> V(n+1);
    vector<int> adj[MAX + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> V[i];
    }

    vector<int> in(n + 1);
    int x, y;
    for (int j = 1; j <= k; ++j) {
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }

    int target;
    cin >> target;

    vector<int> delay(n + 1);
    queue<int> q;
    for (int l = 1; l <= n; ++l) {
        if (!in[l]) {
            delay[l] = V[l];
            q.push(l);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            delay[v] = max(delay[v], delay[u] + V[v]);
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    return delay[target];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}
