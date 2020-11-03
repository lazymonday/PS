#include <iostream>

using namespace std;

int n;
int dp[31];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= 30; i += 2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = 4; j < ; ++j) {

        }
    }

    cout << dp[n] << "\n";
    return 0;
}
