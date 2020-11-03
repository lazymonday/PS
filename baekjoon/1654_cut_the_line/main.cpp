#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
typedef long long ll;

ll n, m;
ll a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll lo = 1;
    ll hi = (1u << 31u);
    while (lo < hi) {
        ll x = lo + (hi - lo) / 2;
        auto can = [&]() {
            ll cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += a[i] / x;
            }

            return m <= cnt;
        };

        if (can()) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    cout << hi - 1;
    return 0;
}
