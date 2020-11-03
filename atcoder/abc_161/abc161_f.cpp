#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n;
ll dp[MAX + 1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int sz = sqrt(n) + 1;

    for (int k = 2; k <= sz; ++k)
    {
        if (n % k == 0) {
            dp[k] = dp[n / k];
        } else if (n > k) {
            dp[k] = dp[n - k];
        }
    }



    return 0;
}
