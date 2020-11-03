#include <iostream>

using namespace std;
const int MAX = 11 + 1;
int t;

int dp[MAX];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[0] = 1;
    for (int j = 1; j < MAX; ++j) {
        for (int i = max(j - 3, 0); i < j; ++i) {
            dp[j] += dp[i];
        }
    }


    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
