#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
const ll divisor = 1e9 + 3;
const int MAX = 1001;
ll dp[MAX][MAX];
int n, k;

int main() {

    cin >> n >> k;

    dp[1][1] = 0;
    dp[2][1] = 2;
    dp[3][1] = 3;

    for (int j = 0; j <= n; ++j) {
        dp[j][0] = 1;
        dp[j][1] = j;
    }

    for (int i = 2; i <= n; ++i) {
        for (int k = 2; k <= n; ++k) {
            dp[i][k] = (dp[i - 1][k] + dp[i - 2][k - 1]) % divisor;
        }
    }

    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % divisor << "\n";

    return 0;
}
