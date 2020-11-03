#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

const int DIV = 998244353;
int n, s;
int a[3001];
int dp[3001][3001];

void print(int nn, int ss) {
    for (int i = 1; i <= nn; ++i)
    {
        printf("%-2d|", i);
        for (int j = 1; j <= ss; ++j)
        {
            printf("%-2d ", dp[i][j]);
        }

        cout << "\n";
    }
    cout << "--------------------------------\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    printf("   ");
    for (int i = 1; i <= s; ++i)
    {
        printf("%-2d ", i);
    }

    cout << " (weight) \n";
    cout << "---------------------------------\n";

    for (int i = 1; i <= n; ++i)
    {
        dp[i][a[i]] = i;
        for (int j = 1; j <= s; ++j)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % DIV;
            if (j - a[i] > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % DIV;
            }
            print(i, a[i]);
        }
        print(n, s);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + dp[i][s]) % DIV;
    }

    cout << ans % DIV;

    return 0;
}
