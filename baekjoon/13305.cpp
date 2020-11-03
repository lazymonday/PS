#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;
const int INF = 2e9;
typedef long long ll;


int n;
int price[MAX + 1];
int dist[MAX + 1];
ll dp[MAX + 1];
int psum[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> dist[i];
        psum[i] = psum[i - 1] + dist[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> price[i];
    }

    dp[1] = 0;
    int minIdx = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = min(dp[i - 1] + 1ll * price[i - 1] * dist[i - 1], price[minIdx] * 1ll * (psum[i - 1] - psum[minIdx - 1]) + dp[minIdx]);
        if (price[minIdx] > price[i]) {
            minIdx = i;
        }
    }

    cout << dp[n];

    return 0;
}
