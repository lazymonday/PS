#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n, m;
int a[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1][2];

int diff(pair<int, int>& cop, pair<int, int>& target) {
    return abs(cop.first - target.first) + abs(cop.second - target.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].first >> a[i].second;   // row, col
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[]
        }
    }



    return 0;
}
