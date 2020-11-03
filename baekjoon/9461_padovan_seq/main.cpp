#include <iostream>

using namespace std;
const int MAX = 100;
typedef long long ll;
int t;
ll dp[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;

    dp[1] = dp[2] = dp[3] = 1ll;

    for (int i = 4; i <= MAX; ++i) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    int x;
    while (t--) {
        cin >> x;
        cout << dp[x] << "\n";
    }

    return 0;
}
