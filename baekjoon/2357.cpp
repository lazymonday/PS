#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n, m;
pair<int, int> tree[1 << 18];
int num[MAX + 1];

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = {num[left], num[left]};
        return;
    }

    int mid = left + (right - left) / 2;

    init(node * 2, left, mid);
    init(node * 2 + 1, mid + 1, right);

    tree[node] = {min(tree[node * 2].first, tree[node * 2 + 1].first), max(tree[node * 2].second, tree[node * 2 + 1].second)};
}

pair<int, int> query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) {
        return {INF, -INF};
    }

    if (l <= left && right <= r) {
        return tree[node];
    }

    int mid = left + (right - left) / 2;
    auto leftNode = query(node * 2, left, mid, l, r);
    auto rightNode = query(node * 2 + 1, mid + 1, right, l, r);

    return {min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second)};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
    }

    init(1, 1, n);

    int p, q;
    for (int i = 0; i < m; ++i)
    {
        cin >> p >> q;
        auto ret = query(1, 1, n, p, q);
        cout << ret.first << " " << ret.second << "\n";
    }

    return 0;
}
