#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int NODE_MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;
pair<int, int> xp[MAX + 1];
pair<int, int> yp[MAX + 1];
pair<int, int> zp[MAX + 1];

int root[MAX + 1];

int find(int p) {
    if (root[p] == -1) return p;
    return root[p] = find(root[p]);
}

bool uni(int p, int q) {
    if (p == q) return true;
    root[p] = q;
    return false;
}

vector<pair<int, pair<int, int>>> edge;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int x, y, z;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> z;
        xp[i] = {x, i};
        yp[i] = {y, i};
        zp[i] = {z, i};
    }

    sort(xp + 1, xp + n + 1);
    sort(yp + 1, yp + n + 1);
    sort(zp + 1, zp + n + 1);

    edge.resize(3 * n);
    int cur = 0;

    for (int i = 2; i <= n; ++i)
    {
        int diff = abs(xp[i].first - xp[i - 1].first);
        int here = xp[i].second;
        int there = xp[i - 1].second;
        edge[cur++] = {diff, {here, there}};

        diff = abs(yp[i].first - yp[i - 1].first);
        here = yp[i].second;
        there = yp[i - 1].second;
        edge[cur++] = {diff, {here, there}};

        diff = abs(zp[i].first - zp[i - 1].first);
        here = zp[i].second;
        there = zp[i - 1].second;
        edge[cur++] = {diff, {here, there}};
    }

    sort(edge.begin(), edge.begin() + cur);

    memset(root, -1, sizeof root);

    ll ans = 0;
    int mstSize = 0;
    for (int i = 0; i < edge.size() && mstSize < n - 1 ; ++i)
    {
        int here = edge[i].second.first;
        int there = edge[i].second.second;
        if (!uni(find(here), find(there))) {
            ans += 1ll * edge[i].first;
            mstSize++;
        }
    }

    cout << ans;

    return 0;
}
