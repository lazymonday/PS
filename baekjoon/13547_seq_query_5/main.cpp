#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100100;
int n, m;
int freq[1000100];
int nums[MAX];
int sz;
int answer[MAX];


struct Query {
    int index, left, right;

    bool operator<(const Query &rhs) const {
        int l1 = left / sz;
        int l2 = rhs.left / sz;
        return l1 == l2 ? right < rhs.right : left < rhs.left;
    }
};

int add(int idx) {
    if (!freq[nums[idx]]++) {
        return 1;
    }

    return 0;
}

int remove(int idx) {
    if (!(--freq[nums[idx]])) {
        return -1;
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    cin >> m;
    sz = sqrt(n);
    vector<Query> queries(m);
    for (int i = 0; i < m; ++i) {
        queries[i].index = i;
        cin >> queries[i].left >> queries[i].right;
    }

    sort(queries.begin(), queries.end());
    int l = 0;
    int r = 0;
    int count = 0;
    for (int i = 0; i < m; ++i) {
        while (l < queries[i].left) count += remove(l++);
        while (l > queries[i].left) count += add(--l);
        while (r < queries[i].right) count += add(++r);
        while (r > queries[i].right) count += remove(r--);

        answer[queries[i].index] = count;
    }

    for (int i = 0; i < m; ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}
