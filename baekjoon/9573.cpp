#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
int far[3];
int mas[3];

bool check(int key[3], int chk[3]) {
    for (int i = 0; i < 3; ++i)
    {
        int diff = abs(key[i] - chk[i]);
        if (diff > 2 && (n - diff) > 2) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < 3; ++i) cin >> far[i];
    for (int i = 0; i < 3; ++i) cin >> mas[i];

    int overlap = 0;
    int ans = min(5, n);
    ans = (ans * ans * ans) * 2;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                int cand[3] = {i, j, k};
                if (check(far, cand) && check(mas, cand)) {
                    overlap++;
                }
            }
        }
    }

    ans -= overlap;
    cout << ans;

    return 0;
}
