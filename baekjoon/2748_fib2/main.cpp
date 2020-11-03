#include <stdio.h>

using namespace std;
typedef long long ll;

const int MAX = 90;
ll dp[MAX + 1];

int main() {
    int x;
    cin >> x;

    dp[1] = dp[2] = 1;
    for (int i = 3; i <= x; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[x];
    return 0;
}
