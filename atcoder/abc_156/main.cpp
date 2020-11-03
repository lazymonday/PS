#include <iostream>

using namespace std;

const int DIV = 1e9 + 7;
typedef long long ll;
int n, a, b;

int modPow(long long a1, long long n1, int mod) {
    if (n1 == 1) return a1 % mod;
    if (n1 % 2 == 1) return (a1 * modPow(a1, n1 - 1, mod)) % mod;
    long long t = modPow(a1, n1 / 2, mod);
    return (t * t) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;

    ll x = 1;
    ll y = 1;
    for (int i = 0; i < a; ++i) {
        x = (x * (n - i)) % DIV;
        y = (y * (i + 1)) % DIV;
    }

    ll ans = modPow(2, n, DIV) - 1;
    ans = (ans - (x * modPow(y, DIV - 2, DIV))) % DIV;

    y = x = 1;
    for (int i = 0; i < b; ++i) {
        x = (x * (n - i)) % DIV;
        y = (y * (i + 1)) % DIV;
    }

    ans -= (x % DIV * modPow(y, DIV - 2, DIV)) % DIV;
    if (ans < 0) {
        ans = (ans + 2 * DIV) % DIV;
    }

    cout << ans;

    return 0;
}
