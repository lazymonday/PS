#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];
int b[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("cbarn_silver_feb16/5.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != 0) start = i;
        if (a[i] == 0 && a[(i + 1) % n] != 0 && a[(i + 2) % n] != 0) {
            start = (i + 1) % n;
            break;
        }
    }

    int ans = 0;
    int zeroIdx = start;
    for (int i = 0; i < n; ++i)
    {
        int idx = (start + i) % n;
        if (!a[idx]) continue;

        int diff = (zeroIdx >= idx ? zeroIdx - idx : n - idx + zeroIdx);

        for (int j = 0; j < a[idx]; ++j)
        {
            int diff = 0;
            if (zeroIdx >= idx) {
                diff = zeroIdx - idx;
            } else {
                diff = n - idx + zeroIdx;
            }
            ans += diff * diff;
            zeroIdx++;
            if (zeroIdx >= n) zeroIdx = 0;
        }

        if (zeroIdx == start) break;
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << ((i == zeroIdx) ? "[" : " ") << b[i] << ((i == zeroIdx) ? "]" : " ");
        // }
        // cout << "\n";
    }

    cout << ans;

    return 0;
}
