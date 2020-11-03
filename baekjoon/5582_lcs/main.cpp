#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4001;
int dp[MAX][MAX];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(dp[i][j], ans);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
