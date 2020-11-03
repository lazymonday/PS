#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;


int s[12];
int team[4];
int cnt[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 12; ++i)
        cin >> s[i];

    int upper = 1 << 22;
    int ans = INF;
    for (int i = 0; i < upper; ++i)
    {
        memset(cnt, 0, sizeof cnt);
        memset(team, 0, sizeof team);

        team[0] = s[0];
        cnt[0] = 1;

        for (int k = 0; k < 11; ++k)
        {
            int tid = (i >> (2 * k)) & 3;
            team[tid] += s[k + 1];
            cnt[tid]++;
        }

        if (cnt[0] != 3 || cnt[1] != 3 || cnt[2] != 3 || cnt[3] != 3) continue;

        auto ret = minmax_element(team, team + 4);
        ans = min(ans, *ret.second - *ret.first);
    }

    cout << ans;

    return 0;
}
