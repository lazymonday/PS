#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4;
const int INF = 2e9;
typedef long long ll;

struct rule {
    int l, r, cnt;

    bool operator<(const rule &rhs) const {
        if (l == rhs.l) return r < rhs.r;
        return l < rhs.l;
    }
};

rule r[MAX + 1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;

    for (int i = 0; i < k; ++i) {
        cin >> r[i].l >> r[i].r >> r[i].cnt;
    }

    sort(r, r + k);

    ll lo = 1;
    ll hi = n + 1;
    while (lo < hi) {
        ll x = lo + (hi - lo) / 2;
        auto can = [&]() {
            ll nth = 0;
            for (int i = 0; i < k; ++i) {
                if (r[i].l > x) {
                    break;
                }
                nth += ((min(x, (ll)r[i].r) - r[i].l) / r[i].cnt) + 1;
            }

            return nth < d;
        };

        if (can()) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    cout << lo;


    return 0;
}
