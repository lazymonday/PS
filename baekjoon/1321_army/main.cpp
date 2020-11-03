#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 500000;
int n;
int army[MAX + 1];
vector<int> tree;


int init(int node, int left, int right) {
    if (left >= right) {
        return tree[node] = army[left];
    }

    int mid = left + (right - left) / 2;
    return (tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right));
}

void update(int node, int left, int right, int kth, int value) {
    if (kth < left || right < kth) {
        return;
    }

    if (left == right) {
        tree[node] += value;
        return;
    }

    int mid = left + (right - left) / 2;
    update(node * 2, left, mid, kth, value);
    update(node * 2 + 1, mid + 1, right, kth, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query2(int node, int left, int right, int k) {
    if (left == right) {
        return left;
    }

    int mid = left + (right - left) / 2;
    int midSum = tree[node * 2];    // sum(1-mid)
    if (midSum >= k) {
        return query2(node * 2, left, mid, k);
    }

    return query2(node * 2 + 1, mid + 1, right, k - midSum);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> army[i];
    }

    int h = (int) ceil(log2(n)) + 1;
    tree.resize(1 << h);

    init(1, 1, n);

    int ops;
    cin >> ops;
    for (int j = 0; j < ops; ++j) {
        int cmd;
        int a, b;
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b;
            update(1, 1, n, a, b);
        } else {
            cin >> a;
            cout << query2(1, 1, n, a) << "\n";
        }
    }

    return 0;
}
