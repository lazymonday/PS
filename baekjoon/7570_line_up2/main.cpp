#include <iostream>

using namespace std;
const int MAX = 1e6;
int n;
int dp[MAX + 1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    // find longest increment by 1 sequences
    int ans = 0;
    int k;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        ans = max(ans, dp[k] = dp[k - 1] + 1);
    }

    cout << n - ans;

    return 0;
}
