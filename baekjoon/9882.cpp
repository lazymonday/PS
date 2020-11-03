#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n = 12;
int tot = 0;
int score[12];
int teamScore[4];

int solve(int chosen, int taken, int lastPicked) {
    if (chosen > 8) {
        int accum = 0;
        for (int i = 0; i < 3; ++i)
            accum += teamScore[i];

        teamScore[chosen / 3] = tot - accum;
        auto minmax = minmax_element(teamScore, teamScore + 4);
        return *minmax.second - *minmax.first;
    }

    if (chosen % 3 == 0) {
        lastPicked = 0;
    }

    int ret = INF;

    for (int i = lastPicked; i < n; ++i)
    {
        if (taken & (1 << i)) continue;
        teamScore[chosen / 3] += score[i];
        ret = min(ret, solve(chosen + 1, taken | (1 << i), i));
        teamScore[chosen / 3] -= score[i];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < n; ++i) {
        cin >> score[i];
        tot += score[i];
    }
    cout << solve(0, 0, 0);

    return 0;
}
