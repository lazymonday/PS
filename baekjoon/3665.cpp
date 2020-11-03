#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int INF = 1e9;
typedef long long ll;


int n;
int num[MAX + 1];
int indegree[MAX + 1];
vector<int> edge[MAX + 1];

void solve() {

    memset(indegree, 0, sizeof indegree);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < edge[i].size(); ++j)
        {
            indegree[edge[i][j]]++;
        }
    }

    queue<int> q, order;

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        // if (q.size() > 1) {
        //     cout << "?\n";
        //     return;
        // }

        if (q.empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        auto v = q.front();
        q.pop();
        order.push(v);

        for (int j = 0; j < edge[v].size(); ++j)
        {
            int u = edge[v][j];
            if (u == 0) continue;
            if (--indegree[u] == 0) {
                q.push(u);
            }
        }
    }


    while (!order.empty()) {
        cout << order.front() << " ";
        order.pop();
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
            for (int j = 0; j < i; ++j)
            {
                edge[num[j]].push_back(num[i]);
            }
        }

        int m;
        cin >> m;
        int a, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;

            bool found = false;
            for (int k = 0; k < edge[a].size(); ++k)
            {
                if (edge[a][k] == b) {
                    edge[a][k] = 0;
                    edge[b].push_back(a);
                    found = true;
                    break;
                }
            }

            if (!found) {
                for (int k = 0; k < edge[b].size(); ++k)
                {
                    if (edge[b][k] == a) {
                        edge[b][k] = 0;
                        edge[a].push_back(b);
                        break;
                    }
                }
            }
        }

        solve();
        for (int i = 0; i <= n; ++i)
        {
            edge[i].clear();
        }

        memset(num, 0, sizeof num);

    }


    return 0;
}
