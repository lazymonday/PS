#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;


int n;
int pre[MAX + 1];
int in[MAX + 1];

int root_in_inorder(int num, int left, int right) {
    for (int i = left; i <= right; ++i)
    {
        if (in[i] == num) {
            return i;
        }
    }

    return -1;
}

void build_tree(int rootIdx, int left, int right) {

    if (left > right) return;

    int mid = root_in_inorder(pre[rootIdx], left, right);
    build_tree(rootIdx + 1, left, mid - 1);
    build_tree(rootIdx + mid - left + 1, mid + 1, right);

    cout << pre[rootIdx] << " ";
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

        build_tree(1, 1, n);
        cout << "\n";
    }

    return 0;
}
