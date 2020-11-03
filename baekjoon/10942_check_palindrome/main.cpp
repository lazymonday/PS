#include <cstdio>

using namespace std;

const int MAX = 2000;
int n, m;
int seq[MAX + 1];
int dp[MAX + 1][MAX + 1];


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &seq[i]);
    }

    for (int k = 1; k <= n; ++k) {
        dp[k][k] = 1;
    }

    for (int r = 1; r <= MAX; ++r) {
        for (int l = r - 1; l > 0; --l) {
            if (seq[r] == seq[l]) {
                if (r - l < 2) {
                    dp[l][r] = 1;
                } else {
                    dp[l][r] = dp[l + 1][r - 1];
                }
            } else {
                dp[l][r] = 0;
            }
        }
    }

    char answer[2002000];
    scanf("%d", &m);
    int s, e;
    int offset = 0;
    for (int j = 0; j < m; ++j) {
        scanf("%d%d", &s, &e);
        answer[offset] = dp[s][e] + '0';
        answer[offset+1] = '\n';
        offset += 2;
    }

    answer[offset] = '\0';
    printf("%s", answer);

    return 0;
}
