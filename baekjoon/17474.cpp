#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
    Node() {}

    Node(int largest_, int larger_, int count_, ll sum_) :
            largest(largest_),
            larger(larger_),
            count(count_),
            sum(sum_) {}

    int largest;
    int larger;
    int count;
    ll sum;
};


const int MAX = 1e6;
const int CMD_MAX = 2;
const int CMD_SUM = 3;
int n, q;
int nums[MAX + 1];
Node tree[1 << 21];

void merge(const Node &left, const Node &right, Node &ret) {
    if (left.largest == right.largest) {
        ret.largest = left.largest;
        ret.count = left.count + right.count;
        ret.larger = max(left.larger, right.larger);
    } else {
        if (left.largest > right.largest) {
            ret.largest = left.largest;
            ret.larger = max(right.largest, left.larger);
            ret.count = left.count;
        } else {
            ret.largest = right.largest;
            ret.larger = max(left.largest, right.larger);
            ret.count = right.count;
        }
    }

    ret.sum = left.sum + right.sum;
}

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = {nums[left], -1, 1, nums[left]};
        return;
    }

    int mid = left + (right - left) / 2;
    init(node << 1, left, mid);
    init(node << 1 | 1, mid + 1, right);

    merge(tree[node << 1], tree[node << 1 | 1], tree[node]);
}


void lazy_update(int node, int left, int right) {
    if (left != right) {
        for (auto i : {node * 2, node * 2 + 1}) {
            if (tree[node].largest < tree[i].largest) {
                tree[i].sum -= 1 * ll(tree[i].largest - tree[node].largest) * tree[i].count;
                tree[i].largest = tree[node].largest;
            }
        }
    }
}

void update(int node, int left, int right, int l, int r, int x) {
    if (r < left || right < l || tree[node].largest <= x) {
        return;
    }

    lazy_update(node, left, right);
    if (l <= left && right <= r) {
        if (tree[node].larger < x) {
            tree[node].sum -= 1ll * (tree[node].largest - x) * tree[node].count;
            tree[node].largest = x;
            lazy_update(node, left, right);
            return;
        }
    }

    int mid = left + (right - left) / 2;
    update(node << 1, left, mid, l, r, x);
    update(node << 1 | 1, mid + 1, right, l, r, x);
    merge(tree[node << 1], tree[node << 1 | 1], tree[node]);
}

ll query(int node, int left, int right, int l, int r, int cmd) {
    if (r < left || right < l) {
        return 0ll;
    }

    if (l <= left && right <= r) {
        return (ll) (cmd == CMD_MAX ? tree[node].largest : tree[node].sum);
    }

    lazy_update(node, left, right);

    int mid = left + (right - left) / 2;
    ll ret1 = query(node << 1, left, mid, l, r, cmd);
    ll ret2 = query(node << 1 | 1, mid + 1, right, l, r, cmd);
    return (cmd == CMD_MAX ? max(ret1, ret2) : ret1 + ret2);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    init(1, 1, n);

    cin >> q;
    int cmd, L, R, X;
    while (q--) {
        cin >> cmd >> L >> R;
        if (cmd == 1) {
            cin >> X;
            update(1, 1, n, L, R, X);
        } else {
            cout << query(1, 1, n, L, R, cmd) << "\n";
        }
    }

    return 0;
}
