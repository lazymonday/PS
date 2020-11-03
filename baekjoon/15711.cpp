#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5;
const int MAX2 = 2e6;
const int INF = 2e9;
typedef long long ll;

char np[MAX2 + 1];
int prime[MAX + 1];

int era_sieve(int maxn) {

    np[0] = np[1] = 1;
    for (int i = 2; i * i <= maxn; ++i) {
        if (np[i]) continue;
        for (int j = i * i; j <= maxn; j += i) {
            np[j] = 1;
        }
    }
    int cur = 0;
    prime[cur++] = 2;
    for (int i = 3; i <= maxn; i += 2)
    {
        if (np[i]) continue;
        prime[cur++] = i;
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int total = era_sieve(MAX2);
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll sum = a + b;

        if (sum < 4) {
            cout << "NO\n";
        } else if (sum % 2 == 0) {
            cout << "YES\n";
        } else {
            sum -= 2;
            bool found = true;
            for (int i = 0; i < total && 1ll * prime[i] * prime[i] <= sum; ++i)
            {
                if (sum % prime[i] == 0) {
                    found = false;
                    break;
                }
            }
            cout << (found ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
