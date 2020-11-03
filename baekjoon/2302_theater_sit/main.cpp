#include <iostream>

using namespace std;

const int MAX = 40;
int dp[MAX + 1];
bool vip[MAX + 1];
int n, m;

int main() {

    cin >> n >> m;

    int v;
    for (int i = 1; i <= m; ++i) {
        cin >> v;
        vip[v] = true;
    }

    dp[0] = 1;
    dp[1] = 1;
    for (int j = 2; j <= n; ++j) {
        if (vip[j] || vip[j - 1]) {
            dp[j] = dp[j - 1];
        } else {
            dp[j] = dp[j - 1] + dp[j - 2];
        }
    }

    cout << dp[n];

    return 0;
}
