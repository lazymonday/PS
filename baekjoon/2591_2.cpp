#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

char str[42];
int dp[42];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str + 1;

    int len = strlen(str + 1);
    str[0] = '0';
    dp[0] = 1;
    for (int i = 1; i <= len; ++i)
    {
        int s = str[i] - '0';
        if (s != 0) {
            dp[i] = dp[i - 1];
        }

        int sum = (str[i - 1] - '0') * 10 + s;
        if (sum >= 10 && sum <= 34) dp[i] += dp[i - 2];
    }

    cout << dp[len];

    return 0;
}
