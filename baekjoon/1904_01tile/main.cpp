#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;
const int divisor = 15746;
int dp[MAX][2];
int n;


int main() {

    cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i][0] = (dp[i - 2][1] + dp[i - 2][0]) % divisor;
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % divisor;
    }

    cout << (dp[n][0] + dp[n][1]) % divisor << "\n";

    return 0;
}
