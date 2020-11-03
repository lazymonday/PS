#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 3000;
const int INF = 2e9;
typedef long long ll;

int n, b;
int a[MAX + 1];
int dp[MAX + 1][MAX + 1][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < b; ++j) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
            dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + a[i]);
        }
    }

    cout << max(dp[n][b - 1][0], dp[n][b - 1][1]);

    return 0;
}
