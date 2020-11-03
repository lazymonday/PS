#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;

const int MAX = 20;
const int INF = 2e9;
typedef long long ll;

int n;
int x[MAX + 1];
int y[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    ll dist = 2e9;
    double ans = 2e9;
    const int m = 2;
    for (int i = 0; i < (1 << n); i++)
    {
        if (__builtin_popcount(i) * 2 != n) continue;

        ll sx = 0;
        ll sy = 0;
        for (int j = 0; j < n; ++j)
        {
            if ((i & (1 << j)) > 0) {
                sx += x[j];
                sy += y[j];
            } else {
                sx -= x[j];
                sy -= y[j];
            }
        }

        ans = min(ans, sqrt(sx * sx + sy * sy));
    }

    cout << ans;

    return 0;
}
