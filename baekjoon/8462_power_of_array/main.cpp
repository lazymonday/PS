#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const ll MAX = 100100;
int n, t;
int sz;
int freq[1001000];
int nums[MAX];  // input size
ll answer[MAX]; // equal to query

struct Query {
    int index, left, right;

    bool operator<(const Query &rhs) const {
        int l = left / sz;
        int l2 = rhs.left / sz;
        return l == l2 ? (right < rhs.right) : (left < rhs.left);
    }
};

ll inc(int no) {
    ll ret = (freq[nums[no]] * 2ll + 1) * nums[no];
    ++freq[nums[no]];
    return ret;
}

ll dec(int no) {
    ll ret = (freq[nums[no]] * -2ll + 1) * nums[no];
    --freq[nums[no]];
    return ret;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> nums[i];

    vector<Query> queries(t);
    for (int i = 0; i < t; ++i) {
        queries[i].index = i;
        cin >> queries[i].left >> queries[i].right;
    }

    sz = sqrt(t);
    sort(queries.begin(), queries.end());

    ll ans = 0;
    int l0 = 0, r0 = 0;
    for (int i = 0; i < t; ++i) {
        while (l0 < queries[i].left) ans += dec(l0++);
        while (l0 > queries[i].left) ans += inc(--l0);
        while (r0 < queries[i].right) ans += inc(++r0);
        while (r0 > queries[i].right) ans += dec(r0--);

        answer[queries[i].index] = ans;
    }

    for (int i = 0; i < t; ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}
