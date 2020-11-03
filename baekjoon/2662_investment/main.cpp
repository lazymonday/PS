#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAX = 300;
int n, m;
int profit[21][MAX + 1];
int dp[21][MAX + 1];
int invested[21][MAX + 1];

void printInvested(int money, int company) {
    if (company <= 0) {
        return;
    }

    printInvested(money - invested[company][money], company - 1);
    cout << invested[company][money];
    if(company != m) cout << " ";
}

void solve() {

    int ans = 0;
    for (int i = 1; i <= n; ++i) {  // money
        for (int j = 1; j <= m; ++j) {  // company
            int here = 0;
            for (int k = 0; k <= i; ++k) {
                int candidate = dp[j - 1][i - k] + profit[j][k];
                if (here < candidate) {
                    here = candidate;
                    invested[j][i] = k;
                }
            }

            dp[j][i] = here;
        }
    }

    cout << dp[m][n] << "\n";
    printInvested(n, m);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int im;
        cin >> im;
        for (int co = 1; co <= m; ++co) {
            cin >> profit[co][im];
        }
    }

    solve();

    return 0;
}