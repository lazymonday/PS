#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

ll n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    if (k < n) {
        cout << min((n % k), abs(n % k - k));
    } else {
        cout << min(k - n, n);
    }

    return 0;
}
