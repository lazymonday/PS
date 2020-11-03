#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int n, m;
int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }


    ll lo = 0;
    ll hi = 1e18 + 1;

    while (lo < hi) {
        ll x = lo + (hi - lo) / 2ll;
        auto ok = [&]() {
            ll total = 0;
            for (int i = 0; i < n; ++i) {
                total += x / (1ll * a[i]);
                if (total > m) {
                    return false;
                }
            }

            return total < m;
        };

        if (ok()) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    cout << lo;
    return 0;
}
