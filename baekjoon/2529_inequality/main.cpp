#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int n;
char ineq[10];
int taken[10];
int ans[10];

bool cmp(int index, int left, int right) {
    if (ineq[index] == '<') {
        return left < right;
    }

    return left > right;
}

bool solve(int digit, int idx, bool rev) {
    if (idx == n) {
        ans[idx] = digit;
        return true;
    }

    ans[idx] = digit;
    for (int i = (rev ? 0 : 9); (rev ? (i < 10) : (i >= 0)); (rev ? ++i : --i)) {
        if (taken[i]) continue;
        if (!cmp(idx, digit, i)) continue;
        taken[i] = 1;
        if (solve(i, idx + 1, rev)) {
            return true;
        }
        taken[i] = 0;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ineq[i];
    }

    memset(taken, 0, sizeof taken);
    memset(ans, 0, sizeof ans);
    for (int j = 9; j >= 0; --j) {
        taken[j] = 1;
        if (solve(j, 0, false)) {
            break;
        }
        taken[j] = 0;
    }

    for (int i = 0; i <= n; ++i) {
        cout << ans[i];
    }
    cout << "\n";

    memset(taken, 0, sizeof taken);
    memset(ans, 0, sizeof ans);
    for (int j = 0; j < 10; ++j) {
        taken[j] = 1;
        if (solve(j, 0, true)) {
            break;
        }
        taken[j] = 0;
    }

    for (int i = 0; i <= n; ++i) {
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}
