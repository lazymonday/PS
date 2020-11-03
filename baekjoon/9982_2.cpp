#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
int s[12];
int cnt[4];
int team[4];

int solve(int k) {
    if (k >= 12) {
        auto ret = minmax_element(team, team + 4);
        return *ret.second - *ret.first;
    }

    int ans = INF;
    for (int i = 0; i < 4; ++i)
    {
        if (cnt[i] < 3) {
            cnt[i]++;
            team[i] += s[k];
            ans = min(ans, solve(k + 1));
            cnt[i]--;
            team[i] -= s[k];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 12; ++i)
    {
        cin >> s[i];
    }

    cout << solve(0);

    return 0;
}
