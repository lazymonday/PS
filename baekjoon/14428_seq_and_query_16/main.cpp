#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Node;    // num, index
const int INF = 1e9;
const int MAX = 100100;
int n, m;
int nums[MAX];
Node tree[1 << 18];

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = {nums[left], left};
        return;
    }

    int mid = left + (right - left) / 2;
    init(node << 1, left, mid);
    init(node << 1 | 1, mid + 1, right);

    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

void update(int node, int left, int right, int l, int r, int value) {
    if (r < left || right < l) {
        return;
    }

    if (l <= left && right <= r) {
        tree[node] = {value, l};
        return;
    }

    int mid = left + (right - left) / 2;
    update(node << 1, left, mid, l, r, value);
    update(node << 1 | 1, mid + 1, right, l, r, value);

    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

Node query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) {
        return {INF, INF};
    }

    if (l <= left && right <= r) {
        return tree[node];
    }

    int mid = left + (right - left) / 2;
    return min(query(node << 1, left, mid, l, r), query(node << 1 | 1, mid + 1, right, l, r));

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

    int a, b, c;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> a >> b >> c;
        if (a == 1) {
            // update
            update(1, 1, n, b, b, c);
        } else {
            // query
            cout << query(1, 1, n, b, c).second << "\n";
        }
    }

    return 0;
}
