#include <iostream>

using namespace std;

const int MAX = 1e5;
int n, k;
int dp[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    int weight, value;
    for (int j = 1; j <= n; ++j) {      // stuff
        cin >> weight >> value;
        for (int i = k; i >= weight; --i) { // weight
            dp[i] = max(dp[i], dp[i - weight] + value);
        }
    }

    cout << dp[k];


    return 0;
}
