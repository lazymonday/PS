#include <iostream>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int chk[MAX + 1];

ll l, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, r;
    cin >> l >> r;
    int ans = r - l + 1;

    for (ll i = 2; i * i <= r; ++i) {
        for (ll j = ((l - 1) / (i * i) + 1) * i * i; j <= r; j += i * i) {
            if (!chk[j - l]) {
                chk[j - l] = 1;
                ans--;
            }
        }
    }

    cout << ans;

    return 0;
}
