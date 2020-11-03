#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int INF = 2e9;
typedef long long ll;


int m, n;
pair<int, int> acc[MAX + 2];
int dp[MAX + 2][MAX + 2];
int choice[MAX + 2][MAX + 2];

int dist(int src, int dest, int car) {
    if (src == 0) {
        src = (car == 1 ? 0 : n + 1);
    }

    return abs(acc[src].first - acc[dest].first) + abs(acc[src].second - acc[dest].second);
}

int solve(int p1, int p2) {
    if (p1 >= n || p2 >= n) {
        return 0;
    }

    auto& ret = dp[p1][p2];
    if (ret != -1) {
        return ret;
    }

    int next = max(p1, p2) + 1;

    ret = solve(next, p2) + dist(p1, next, 1);
    int d2 = solve(p1, next) + dist(p2, next, 2);
    if (d2 < ret) {
        choice[p1][p2] = 1;
        ret = d2;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> acc[i].first >> acc[i].second;
    }

    acc[0] = {1, 1};
    acc[n + 1] = {m, m};

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0) << "\n";

    for (int i = 0, j = 0; max(i, j) < n; )
    {
        cout << choice[i][j] + 1 << "\n";
        if (choice[i][j]) j = max(i, j) + 1;
        else i = max(i, j) + 1;
    }

    return 0;
}
