#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;
pair<int, int> a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int pos, speed;
    for (int i = 0; i < n; ++i)
    {
        cin >> pos >> speed;
        a[i] = {pos, speed};
    }

    int ans = n;
    ll t = 1e9;
    for (int i = n - 1; i > 0; --i)
    {
        ll p1 = a[i].first + a[i].second * t;
        ll p2 = a[i - 1].first + a[i - 1].second * t;
        if (p2 > p1) {
            ans--;
            a[i-1].second = a[i].second;
        }
    }

    cout << ans;
    return 0;
}
