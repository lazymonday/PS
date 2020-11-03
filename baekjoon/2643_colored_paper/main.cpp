#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
int n;

pair<int, int> cp[MAX + 1];
int dp[MAX + 1];

int solve() {

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int here = 0;
        for (int j = 1; j < i; ++j) {
            if ((cp[i].first >= cp[j].first && cp[i].second >= cp[j].second) ||
                (cp[i].first >= cp[j].second && cp[i].second >= cp[j].first)) {
                here = max(here, dp[j]);
            }
        }
        dp[i] = here + 1;
        ans = max(dp[i], ans);
    }

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin >> n;

    int w, h;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> h;
        if(w < h) swap(w, h);
        cp[i] = {w, h};
    }

    sort(cp + 1, cp + n + 1);

    cout << solve() << "\n";

    return 0;
}
