#include <iostream>

using namespace std;

const int INF = 1e9;
int n;
int dp[3];

int solve(int k, int cnt) {
    if (k == 1) {
        return cnt;
    }

    auto &ret = dp[k % 3];
    if (ret != -1) {
        if (ret <= cnt) {
            return ret;
        }
    } else {
        ret = INF;
    }

    if (k % 3 == 0) {
        ret = min(ret, solve(k / 3, cnt + 1));
    }
    if (k % 2 == 0) {
        ret = min(ret, solve(k / 2, cnt + 1));
    }

    ret = min(ret, solve(k - 1, cnt + 1));
    return ret;
}

int main2() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < 3; ++i) dp[i] = -1;
    cout << solve(n, 0);
    return 0;
}

int D[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        D[i] = D[i - 1] + 1;
        if (i % 3 == 0) {
            D[i] = min(D[i], D[i / 3] + 1);
        }
        if (i % 2 == 0) {
            D[i] = min(D[i], D[i / 2] + 1);
        }
    }

    cout << D[n];
}