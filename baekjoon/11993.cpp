#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];

ll square_sum(ll k) {
    return k * (k + 1) * (2 * k + 1) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    ll mov = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mov = max(0ll, mov + a[i] - 1);
    }


    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (mov == 0) {
            start = i;
            break;
        }

        mov = max(0ll, mov + a[i] - 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int idx = (start + i) % n;
        ans += square_sum(a[idx] + mov - 1) - square_sum(mov - 1);
        mov = max(0ll, mov + a[idx] - 1);
    }

    cout << ans;

    return 0;
}
