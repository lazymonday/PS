#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5;
const int INF = 2e9;
typedef long long ll;

ll comb(ll n, ll r) {

    if (n < r) {
        return 0;
    }

    if (n == r || r == 0) {
        return 1;
    }

    ll x = 1;
    ll y = 1;
    for (ll i = 0; i < r; ++i)
    {
        x = x * (n - i);
        y = y * (i + 1);
    }

    return x / y;
}

ll n;
ll a[MAX + 1];
ll cnt[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll total = 0;
    for (int i = 0; i < MAX + 1; ++i)
    {
        if (cnt[i])
            total += comb(cnt[i], 2);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << total - comb(cnt[a[i]], 2) + comb(cnt[a[i]] - 1, 2) << "\n";
    }

    return 0;
}
