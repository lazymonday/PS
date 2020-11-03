#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e7;

ll seq[MAX + 1];

int main() {
    ll N, K;

    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        seq[a] += k;
        if ((b + 1) <= N) seq[b + 1] -= k;
    }

    ll ans = 0, x = 0;
    for (int i = 1; i <= N; i++)
    {
        x = x + seq[i];
        ans = max(ans, x);
    }

    cout << ans;
    return 0;
}