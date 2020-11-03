#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4;
const int INF = 1e9;
typedef long long ll;

int n, X, Y, Z;

pair<int, int> all[MAX * 2 + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> X >> Y >> Z;

    int lo, hi;
    for (int i = 0; i < n; ++i)
    {
        cin >> lo >> hi;
        all[i * 2] = {lo, 1};
        all[i * 2 + 1] = {hi + 1, -1};
    }

    all[2 * n] = {1e9, 0};

    sort(all, all + 2 * n);

    int ans = X * n;
    int maxAns = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (all[i].second == 1) ans += Y - X;
        else if (all[i].second == -1) ans += Z - Y;

        maxAns = max(maxAns, ans);
    }

    cout << maxAns;

    return 0;
}
