#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e7;
ll tree[1 << 25];
ll lazy[1 << 25];
int n, m;

void update_lazy(int node, int left, int right) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int l, int r, ll val) {
    update_lazy(node, left, right);
    if (r < left || right < l) {
        return;
    }

    if (l <= left && right <= r) {
        lazy[node] += val;
        update_lazy(node, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    update(node * 2, left, mid, l, r, val);
    update(node * 2 + 1, mid + 1, right, l, r, val);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, k;
        cin >> a >> b >> k;
        update(1, 1, n, a, b, k);
    }

    cout << tree[1] << "\n";
    return 0;
}