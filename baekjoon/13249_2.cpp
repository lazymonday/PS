#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int t;
    cin >> t;

    sort(a, a + n);

    double ans = 0;
    for (int k = 0; k < (1 << n); ++k)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if ((k & (1 << i)) != 0 && (k & (1 << j)) == 0) {
                    if (a[i] - a[j] <= 2 * t) cnt++;
                }
            }
        }

        ans += cnt / (1.0 * (1 << n));
    }

    cout << ans;
    return 0;
}
