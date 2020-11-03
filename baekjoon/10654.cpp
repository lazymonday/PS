#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

ll n, T;
pair<ll, ll> a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> T;
    int pos, speed;
    for (int i = 0; i < n; ++i)
    {
        cin >> pos >> speed;
        a[i] = {pos, speed};
    }

    int ans = n;
    a[n - 1].first += a[n - 1].second * T;
    for (int i = n - 1; i > 0; --i)
    {
        ll pos = a[i - 1].first + a[i - 1].second * T;
        if (pos >= a[i].first) {
            ans--;
            a[i - 1].first = a[i].first;
        } else {
            a[i - 1].first = pos;
        }
    }

    cout << ans;
    return 0;
}
