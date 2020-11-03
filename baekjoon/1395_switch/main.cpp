#include <iostream>

using namespace std;

int n, m;
int tree[(1 << 18) + 1];
int lazy[(1 << 18) + 1];

void update_lazy(int node, int left, int right) {
    if (lazy[node]) {
        tree[node] = (right - left + 1) - tree[node];
        if (left != right) {
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
        }

        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int l, int r) {
    update_lazy(node, left, right);
    if (r < left || right < l) {
        return;
    }

    if (l <= left && right <= r) {
        lazy[node] ^= 1;
        update_lazy(node, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    update(node << 1, left, mid, l, r);
    update(node << 1 | 1, mid + 1, right, l, r);

    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int node, int left, int right, int l, int r) {
    update_lazy(node, left, right);
    if (r < left || right < l) {
        return 0;
    }

    if (l <= left && right <= r) {
        return tree[node];
    }

    int mid = left + (right - left) / 2;
    return query(node << 1, left, mid, l, r) + query(node << 1 | 1, mid + 1, right, l, r);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int o, s, t;
    for (int i = 0; i < m; ++i) {
        cin >> o >> s >> t;
        if (o == 0) {
            update(1, 1, n, s, t);
        } else {
            cout << query(1, 1, n, s, t) << "\n";
        }
    }

    return 0;
}
