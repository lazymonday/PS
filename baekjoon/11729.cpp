#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20;
const int INF = 2e9;
typedef long long ll;

int dp[MAX + 1];
int n;

void solve(int from, int to, int by, int cnt) {

    if (cnt == 1) {
        cout << from << " " << to << "\n";
        return;
    }

    solve(from, by, to, cnt - 1);
    cout << from << " " << to << "\n";
    solve(by, to, from, cnt - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] * 2 + 1;
    }

    cout << dp[n] << "\n";
    solve(1, 3, 2, n);

    return 0;
}
