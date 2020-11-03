// ABC158, F, Removing Robots
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;
const int MAX = 2e5;
const int divisor = 998244353;
int n;
pair<int, int> a[MAX + 1];
int dp[MAX + 1];
int tree[1 << 19];

void update(int node, int left, int right, int idx, int v) {

    if (idx < left || right < idx) {
        return;
    }

    if (left == right) {
        tree[node] = v;
        return;
    }

    int mid = (left + right) >> 1;
    update(node << 1, left, mid, idx, v);
    update(node << 1 | 1, mid + 1, right, idx, v);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

int query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) {
        return 0;
    }

    if (l <= left && right <= r) {
        return tree[node];
    }

    int mid = (left + right) >> 1;
    return max(query(node << 1, left, mid, l, r), query(node << 1 | 1, mid + 1, right, l, r));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    dp[n] = 1;
    update(1, 1, n, n, n);
    for (int k = n - 1; k >= 0; --k) {
        int r = lower_bound(a, a + n, pair<int, int>{a[k].first + a[k].second, 0}) - a - 1;
        int p = k + 1;
        if (k + 1 <= r) {
            p = query(1, 1, n, k + 1, r);
        }
        dp[k] = (dp[k + 1] + dp[p]) % divisor;
        update(1, 1, n, k, p);
    }

//    vector<pair<int, int>> L(1, {1e9, n});
//    for (int k = n - 1; k >= 0; --k) {
//        while (L.back().first < a[k].first + a[k].second) L.pop_back();
//        dp[k] = (dp[k + 1] + dp[L.back().second]) % divisor;
//        L.emplace_back(a[k].first, k);
//    }

    cout << dp[0];
    return 0;
}
