#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
const int INF = 1e9;
typedef long long ll;

int color[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, k;
    int total = 0;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> color[i];
        total += color[i];
    }

    cin >> k;

    double ans = 0;
    for (int i = 0; i < m; ++i)
    {
        double expected = 1.0;
        for (int j = 0; j < k; ++j)
        {
            expected *= (double)(color[i] - j) / (double)(total - j);
        }
        ans += expected;
    }


    cout << fixed << setprecision(10);
    cout << ans;



    return 0;
}
