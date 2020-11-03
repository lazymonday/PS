#include <iostream>

using namespace std;

const int MAX = 300;
int n;
int dp[MAX + 3][2];
int score[MAX + 3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
    }

    dp[1][1] = score[1];
    for (int j = 2; j <= n; ++j) {
        dp[j][0] = dp[j - 1][1] + score[j];
        dp[j][1] = max(dp[j - 2][0], dp[j - 2][1]) + score[j];
    }

    cout << max(dp[n][0], dp[n][1]);

    return 0;
}
