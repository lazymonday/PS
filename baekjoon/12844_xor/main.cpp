#include <iostream>

using namespace std;

const int MAX = 5e5;
int tree[1 << 20];
int lazy[1 << 20];
int n;
int nums[MAX + 1];

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = nums[left];
        return;
    }

    int mid = (left + right) >> 1;
    init(node << 1, left, mid);
    init(node << 1 | 1, mid + 1, right);

    tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

void lazy_update(int node, int left, int right) {
    if (lazy[node]) {
        if ((right - left + 1) & 1) {
            tree[node] ^= lazy[node];
        }

        if (left != right) {
            lazy[node << 1] ^= lazy[node];
            lazy[node << 1 | 1] ^= lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int l, int r, int v) {
    lazy_update(node, left, right);
    if (r < left || right < l) {
        return;
    }

    if (l <= left && right <= r) {
        lazy[node] ^= v;
        lazy_update(node, left, right);
        return;
    }

    int mid = (left + right) >> 1;
    update(node << 1, left, mid, l, r, v);
    update(node << 1 | 1, mid + 1, right, l, r, v);

    tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

int query(int node, int left, int right, int l, int r) {
    lazy_update(node, left, right);
    if (r < left || right < l) {
        return 0;
    }

    if (l <= left && right <= r) {
        return tree[node];
    }

    int mid = (left + right) >> 1;
    return query(node << 1, left, mid, l, r) ^ query(node << 1 | 1, mid + 1, right, l, r);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    init(1, 1, n);

    int m;
    cin >> m;
    int cmd, a, b, c;
    for (int j = 0; j < m; ++j) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b >> c;
            if (a > b) swap(a, b);
            update(1, 1, n, a + 1, b + 1, c);
        } else {
            cin >> a >> b;
            if (a > b) swap(a, b);
            cout << query(1, 1, n, a + 1, b + 1) << "\n";
        }
    }

    return 0;
}
