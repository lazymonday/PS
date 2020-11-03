#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAX = 2000 * 2;
int dp[MAX + 1];
int lps[MAX + 1];   // longest palindrome substring
char str[MAX + 1];

void manachers(int len) {
    int c = -1;
    int r = -1;

    for (int i = 0; i < len; ++i) {
        if (r >= i) {
            lps[i] = min(r - i, lps[c * 2 - i]);    // pos of symmetric
        } else {
            lps[i] = 0;
        }

        while ((i + lps[i] + 1) < len && (i - lps[i] - 1) >= 0 && (str[i + lps[i] + 1] == str[i - lps[i] - 1]))
            ++lps[i];

        if (r < i + lps[i]) {
            r = i + lps[i];
            c = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string seq;
    cin >> seq;
    int len = seq.size();
    for (int i = 0; i < len; ++i) {
        str[i * 2] = seq[i];
    }
    len = len * 2 - 1;

    manachers(len);

    dp[0] = 1;
    for (int j = 2; j < len; j += 2) {
        dp[j] = INF;
        for (int i = 0; i <= j; i += 2) {
            int c = (i + j) / 2;
            int r = (j - i) / 2;
            if (lps[c] >= r) {
                dp[j] = min(dp[j], (i < 2 ? 1 : dp[i - 2] + 1));
            }
        }
    }

    cout << dp[len - 1];

    return 0;
}
