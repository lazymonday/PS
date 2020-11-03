#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1001;
int dp[MAX][MAX];

int main() {

    char a[1001] = {0};
    char b[1001] = {0};
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    int la = strlen(a + 1);
    int lb = strlen(b + 1);

    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i][j - 1] < dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    char seq[1000] = {0};
    int ans = dp[la][lb];
    int cur = lb;
    for (int r = la; r >= 1; --r) {
        int c = cur;
        if (ans <= 0) break;
        while (dp[r][c] == ans) --c;
        if (a[r] == b[c + 1]) {
            seq[ans - 1] = a[r];
            ans--;
            cur = c + 1;
        }
    }

    printf("%d\n", dp[la][lb]);
    for (int l = 0; l < dp[la][lb]; ++l) {
        printf("%c", seq[l]);
    }

    return 0;
}
