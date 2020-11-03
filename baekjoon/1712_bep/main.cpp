#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;

    cin >> a >> b >> c;

    ll lo = 0;
    ll hi = 1e8 * 21;

    while (lo < hi) {
        ll x = lo + (hi - lo) / 2;
        if (c * x < a + b * x) {
            lo = x + 1;
        } else {
            hi = x;
        }
    }

    if (a + b * lo <= lo * c) {
        if (a + b * lo == lo * c) lo++;
        cout << lo;
    } else {
        cout << -1;
    }

    return 0;
}
