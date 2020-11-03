#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500;
int dp[MAX + 1];
int line[MAX + 1];
int n;

int main() {

    cin >> n;
    int start, end;
    for (int k = 1; k <= n; ++k) {
        line[start] = end;
    }

    int ans = 0;
    for (int i = 1; i <= MAX; ++i) {
        int here = 0;
        if (!line[i]) continue;
        for (int j = i - 1; j > 0; --j) {
            if (!line[j]) continue;
            if (line[i] > line[j]) {
                here = max(here, dp[j]);
            }
        }
        dp[i] = here + 1;
        ans = max(ans, dp[i]);
    }

    cout << n - ans << "\n";

    return 0;
}
