#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;
int n, m;
int psum[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int largest = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> psum[i];
        largest = max(largest, psum[i]);
        psum[i] += psum[i - 1];
    }

    int lo = largest - 1;
    int hi = psum[n];

    while (lo + 1 < hi) {
        int x = lo + (hi - lo) / 2;

        auto can = [&]() {
            int cnt = 1, last = 0;
            for (int i = 0; i < n; ++i) {
                if (psum[i + 1] - psum[last] > x) {
                    ++cnt;
                    last = i;
                }
            }

            return m < cnt;
        };

        if (can()) {
            lo = x;
        } else {
            hi = x;
        }
    }

    cout << hi;

    return 0;
}
