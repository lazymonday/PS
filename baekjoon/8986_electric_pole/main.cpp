#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;
ll n;
ll a[MAX + 1];

ll calc(ll inter) {
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += abs(i * inter - a[i]);
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int lo = 0;
    int hi = 1e9;

    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        if (calc(x + 1) < calc(x)) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    cout << calc(lo);
    return 0;
}
