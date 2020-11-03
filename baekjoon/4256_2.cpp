#include <bits/stdc++.h>

using namespace std;

const int MAX = 32;
const int INF = 1e9;
typedef long long ll;


int n;
int pre[MAX + 1];
int in[MAX + 1];
int tree[1 << 7];

void postOrder(int pos) {
    if (tree[pos] == 0) return;
    postOrder(pos * 2);
    postOrder(pos * 2 + 1);
    cout << "[" << pos << "]"<< tree[pos] << " ";
}

int root_in_inorder(int num, int left, int right) {

    for (int i = left; i <= right; ++i)
    {
        if (in[i] == num) {
            return i;
        }
    }

    return -1;
}

void build_tree(int idx, int rootIdx, int left, int right) {

    if (left > right) return;

    tree[idx] = pre[rootIdx];
    int mid = root_in_inorder(tree[idx], left, right);
    build_tree(idx * 2, rootIdx + 1, left, mid - 1);
    build_tree(idx * 2 + 1, rootIdx + mid - left + 1, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        cin >> n;

        for (int i = 1; i <= n; ++i) cin >> pre[i];
        for (int i = 1; i <= n; ++i) cin >> in[i];

        build_tree(1, 1, 1, n);

        postOrder(1);
        cout << "\n";
        memset(tree, 0, sizeof tree);
    }

    return 0;
}
