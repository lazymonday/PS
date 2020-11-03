#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
int loc[MAX + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> loc[i];
    }

    sort(loc, loc + n);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int XY = loc[j] - loc[i];
            auto pos1 = lower_bound(loc + j, loc + n, loc[j] + XY);
            auto pos2 = upper_bound(loc + j, loc + n, loc[j] + 2 * XY);
            ans += pos2 - pos1;
        }
    }

    cout << ans;

    return 0;

}