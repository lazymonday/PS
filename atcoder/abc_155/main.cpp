#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX = 2e5;
int a[MAX + 1];
ll n, k;

bool lessThanK(ll x, ll k) {
    ll skip = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            int l = -1, h = n;
            while (l + 1 < h) {
                int m = l + (h - l) / 2;
                if (1ll * a[i] * a[m] < x) {
                    h = m;
                } else {
                    l = m;
                }
            }
            skip += n - h;
        } else {
            int l = -1, h = n;
            while (l + 1 < h) {
                int m = l + (h - l) / 2;
                if (1ll * a[i] * a[m] < x) {
                    l = m;
                } else {
                    h = m;
                }
            }
            skip += h;
        }

        if (1ll * a[i] * a[i] < x) skip--;
    }

    skip /= 2;
    return skip < k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    ll lo = ll(-1e18);
    ll hi = ll(1e18) + 1;
    while (lo < hi) {
        ll x = lo + (hi - lo) / 2;
        if (lessThanK(x, k)) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    cout << lo - 1;

    return 0;
}