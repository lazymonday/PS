#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<int> tree[MAX * 3];
int nums[MAX + 1];

void init(int node, int left, int right) {

    if (left >= right) {
        tree[node].push_back(nums[left]);
        return;
    }

    int mid = left + (right - left) / 2;
    init(node * 2, left, mid);
    init(node * 2 + 1, mid + 1, right);

    vector<int> &l = tree[node * 2];
    vector<int> &r = tree[node * 2 + 1];
    int i = 0;
    int j = 0;
    while (i < l.size() && j < r.size()) {
        if (l[i] < r[j]) {
            tree[node].push_back(l[i]);
            ++i;
        } else {
            tree[node].push_back(r[j]);
            ++j;
        }
    }

    while (i < l.size()) {
        tree[node].push_back(l[i++]);
    }
    while (j < r.size()) {
        tree[node].push_back(r[j++]);
    }
}

int query(int node, int l, int r, int i, int j, int k) {

    if (r < i || j < l) {
        return 0;
    }

    if (i <= l && r <= j) {
        return lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    }

    int mid = l + (r - l) / 2;
    return query(node * 2, l, mid, i, j, k) + query(node * 2 + 1, mid + 1, r, i, j, k);
}


int n, m;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    init(1, 1, n);

    int i, j, k;
    for (int l = 0; l < m; ++l) {
        cin >> i >> j >> k;

        int hi = 1e9;
        int lo = -1e9;
        while (hi > lo) {
            int mid = lo + (hi - lo) / 2;
            int ret = query(1, 1, n, i, j, mid);
            if (ret < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        cout << lo - 1 << "\n";
    }

    return 0;
}
