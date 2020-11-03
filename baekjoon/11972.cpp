#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int N, M, D, S;
vector<pair<int, int>> ate[55];
int sick[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; ++i)
    {
        int p, m, t;
        cin >> p >> m >> t;
        ate[m].push_back({p, t});
    }

    for (int i = 0; i < S; ++i)
    {
        int p, t;
        cin >> p >> t;
        sick[p] = t;
    }

    int ans = 0;
    for (int i = 1; i <= M; ++i)
    {
        int cand = 0;
        int sicked[55];
        memset(sicked, 0, sizeof sicked);
        for (auto eat : ate[i]) {
            if (sick[eat.first]) {
                if (sick[eat.first] > eat.second) {
                    sicked[eat.first] = 1;
                }
            } else {
                sicked[eat.first] = 1;
            }
        }

        for (int k = 1; k <= N; ++k) {
            if (sick[k] && !sicked[k]) {
                cand = 0;
                break;
            }
            if (sicked[k]) cand++;
        }

        ans = max(ans, cand);
    }

    cout << ans;

    return 0;
}
