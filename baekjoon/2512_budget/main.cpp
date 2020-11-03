#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4;
const int INF = 1e9;
typedef long long ll;
int n;
ll m;
int num[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int maxBudget = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        maxBudget = max(maxBudget, num[i]);
        sum += num[i];
    }

    cin >> m;

    if (sum <= m) {
        cout << maxBudget;
        return 0;
    }

    int lo = 0, hi = maxBudget;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        auto can = [&]() {
            ll tot = 0;
            for (int i = 0; i < n; ++i) {
                tot += min(num[i], mid);
            }

            return tot <= m;
        };

        if (can()) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo;

    return 0;
}
