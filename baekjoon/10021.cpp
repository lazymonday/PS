#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000;
const int INF = 1e9;
typedef long long ll;

int n, c;
vector<pair<int, pair<int, int>>> edges;
pair<int, int> f[MAX + 1];

int parent[MAX + 1];
int find(int p) {
    if (parent[p] == -1) return p;
    return parent[p] = find(parent[p]);
}

bool uni(int p, int q) {
    p = find(p);
    q = find(q);

    if (p == q) return false;
    parent[p] = q;
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i].first >> f[i].second;
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            int diffX = f[i].first - f[j].first;
            int diffY = f[i].second - f[j].second;
            int cost = diffX * diffX + diffY * diffY;
            if (cost < c) continue;

            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    memset(parent, -1, sizeof parent);

    int mstSz = 0;
    ll ans = 0;
    for (int i = 0; i < edges.size(); ++i)
    {
        if (uni(edges[i].second.first, edges[i].second.second)) {
            mstSz++;
            ans += edges[i].first;
        }

        if (mstSz == n - 1) break;
    }

    if (mstSz < n - 1) {
        cout << -1;
    } else {
        cout << ans;
    }


    return 0;
}
