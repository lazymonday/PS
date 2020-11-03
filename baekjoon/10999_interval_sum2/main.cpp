#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> arr;

class SegmentTree {
    vector<ll> tree;
    vector<ll> lazy;

public:

    SegmentTree(int n) : tree(n), lazy(n) {
    }

    ll init(int node, int left, int right) {
        if (left == right) {
            return (tree[node] = arr[left]);
        }

        int mid = left + (right - left) / 2;
        tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
        return tree[node];
    }


    void update_range(int node, int start, int end, int i, int j, ll value) {
        if (lazy[node] != 0) {
            // 아래로 전파.
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (j < start || end < i) {
            return;
        }

        if (i <= start && end <= j) {
            tree[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }

        int m = start + (end - start) / 2;
        update_range(node * 2, start, m, i, j, value);
        update_range(node * 2 + 1, m + 1, end, i, j, value);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query(int node, int start, int end, int i, int j) {

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (j < start || end < i) {
            return 0LL;
        }

        if (i <= start && end <= j) {
            return tree[node];
        }

        int m = start + (end - start) / 2;
        return query(node * 2, start, m, i, j) + query(node * 2 + 1, m + 1, end, i, j);
    }

};

int main() {

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    int h = (int) ceil(log2(n));
    int treeSize = (1 << (h + 1)) - 1;

    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
    }

    SegmentTree st(treeSize);
    st.init(1, 1, n);

    int a, b, c;
    ll d;
    for (int j = 0; j < m + k; ++j) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %d %lld", &b, &c, &d);
            st.update_range(1, 1, n, b, c, d);
        } else {
            scanf("%d %d", &b, &c);
            printf("%lld\n", st.query(1, 1, n, b, c));
        }
    }

    return 0;
}
