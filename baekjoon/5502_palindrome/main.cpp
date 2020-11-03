#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 5000;
char str[5101];
int dp[MAX + 1][MAX + 1];
int n;

int solve_iterative() {

    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (str[i] == str[j]) {
                dp[j][i] = dp[j + 1][i - 1];
            } else {
                dp[j][i] = min(dp[j][i - 1], dp[j + 1][i]) + 1;
            }
        }
    }

    return dp[1][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin.getline(str+1, 1);
    cin.getline(str+1, 5100);

    cout << solve_iterative();
    return 0;
}
