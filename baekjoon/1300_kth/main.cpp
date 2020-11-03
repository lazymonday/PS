#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (k == n * n) {
        cout << n * n;
        return 0;
    }

    int lo = 1;
    //ll hi = min(1e10, 1e9) + 1;
    int hi = k;  // 모든 k번째 수는 마지막 수를 빼고 k보다 작음.

    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        auto can = [&]() {
            int nth = 0;
//            for (ll i = 1; i <= n; ++i) {
//                nth += min(x / i, (ll) n);
//            }

            int i = 1;
            for (; i * i <= x; ++i) {
                nth += min(x / i, n);
            }
            nth = nth * 2 - (i - 1) * (i - 1);
            return nth < k;
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
