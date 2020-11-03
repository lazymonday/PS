#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;
int n, m;
int h[MAX + 1];

bool over(int x) {
    ll total = 0;
    auto pos = lower_bound(h, h + n, x) - h;
    for (int i = pos; i < n; ++i) {
        total += (ll) h[i] - x;
    }

    return total >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    sort(h, h + n);

    int lo = 0, hi = INF;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (over(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo;

    return 0;
}
