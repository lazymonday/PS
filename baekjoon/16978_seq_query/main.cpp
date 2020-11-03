#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX = 1e5;
ll nums[MAX + 1];
ll tree[1 << 18];
//ll lazy[1 << 18];

struct Query {
    int idx, cmd, l, r, val, oidx;

    bool operator<(const Query &o) const {
        if (idx != o.idx) return idx < o.idx;
        return cmd < o.cmd;
    }
};

Query qs[100001];
int n, q;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = nums[left];
        return;
    }

    int mid = left + (right - left) / 2;
    init(node << 1, left, mid);
    init(node << 1 | 1, mid + 1, right);

    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int node, int left, int right, int l, int r, ll val) {
    if (r < left || right < l) {
        return;
    }

    if (l <= left && right <= r) {
        tree[node] = val;
        return;
    }

    int mid = left + (right - left) / 2;
    update(node << 1, left, mid, l, r, val);
    update(node << 1 | 1, mid + 1, right, l, r, val);

    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

ll query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) {
        return 0ll;
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

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    init(1, 1, n);

    int outCount = 0;
    int updateIndex = 1;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        cin >> qs[j].cmd;
        if (qs[j].cmd == 1) {   // update
            cin >> qs[j].l >> qs[j].val;
            qs[j].idx = updateIndex++;
            qs[j].r = qs[j].l;
        } else {    // query
            cin >> qs[j].idx >> qs[j].l >> qs[j].r;
            qs[j].oidx = outCount++;
        }
    }

    vector<ll> answer(outCount);
    stable_sort(qs, qs + q);
    for (int k = 0; k < q; ++k) {
        if (qs[k].cmd == 1) {
            update(1, 1, n, qs[k].l, qs[k].r, qs[k].val);
        } else {
            answer[qs[k].oidx] = query(1, 1, n, qs[k].l, qs[k].r);
        }
    }

    for (int l = 0; l < outCount; ++l) {
        cout << answer[l] << "\n";
    }

    return 0;
}
