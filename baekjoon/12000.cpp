#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
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

    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        int cand = 0;
        for (int j = 0; j < n; ++j)
        {
            int index = (i + j) % n;
            cand += a[index] * j;
        }

        ans = min(cand, ans);
    }

    cout << ans;

    return 0;
}
