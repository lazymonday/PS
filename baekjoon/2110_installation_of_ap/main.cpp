#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5;
const int INF = 1e9;
typedef long long ll;

int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    int lo = 1;
    int hi = 1e9 + 1;
    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        auto can = [&]() {
            int cnt = 1;
            int last = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] - a[last] >= x) {
                    last = i;
                    cnt++;
                }
            }

            return c <= cnt;
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
