#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e5;
const int INF = 1e9;
typedef long long ll;

int n;
pair<int, int> a1[MAX + 1];
pair<int, int> a2[MAX + 1];
pair<int, int> pw[MAX + 1];
ll tree[(1 << 20)+1];

ll query(int p) {

    ll ret = 0;
    while (p > 0) {
        ret += tree[p];
        p -= (p & -p);
    }
    return ret;
}

void update(int p) {
    while (p <= n) {
        tree[p] += 1ll;
        p += (p & -p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        a1[i] = {a, i};
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        a2[i] = {a, i};
    }

    sort(a1, a1 + n);
    sort(a2, a2 + n);

    for (int i = 0; i < n; ++i)
    {
        pw[i] = {a1[i].second, a2[i].second};
    }

    sort(pw, pw + n);

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int p = pw[i].second + 1;
        ans += query(n) - query(p);
        update(p);
    }

    cout << ans;


    return 0;
}
