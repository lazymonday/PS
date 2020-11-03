#include <iostream>

using namespace std;

const int MAX = 1000;
const int MAX_TIME = 10000;
int n, t;
int est[MAX + 1];
int score[MAX + 1];
int dp[101][MAX_TIME + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;

    for (int i = 1; i <= n; ++i) {
        cin >> est[i] >> score[i];
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 0; i <= MAX_TIME; ++i) {
            if (i >= est[j]) {
                dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - est[j]] + score[j]);
            } else {
                dp[j][i] = dp[j - 1][i];
            }
        }
    }

    //cout << dp[n][t];

    int D[10001] = {};
    for (int j = 1; j <= n; ++j) {
        for (int i = t; i >= est[j]; --i) {
            //cout << "(" << i << "<-" << i - est[j] << ") ";
            D[i] = max(D[i], D[i - est[j]] + score[j]);
        }
        cout << "\n";
    }

    cout << "\n" << D[t];

    return 0;
}
