#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 2020;
int n;
char str[MAX + 2];
int dp[MAX + 1][MAX + 1];
int d[MAX + 1];


int main() {
    scanf("%s", str + 1);
    while (isalpha(*(str + 1 + n))) ++n;

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
        d[i] = i;
    }

    for (int j = 1; j <= n; ++j) {
        d[j] = d[j - 1] + 1;
        for (int i = j - 1; i > 0; --i) {
            if (str[i] == str[j]) {
                if (j - i < 2) {
                    dp[i][j] = 1;
                } else {
                    if (dp[i + 1][j - 1]) {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j]) {
                    d[j] = min(d[j], min(d[j - 1] + 1, d[i - 1] + 1));
                }
            }
        }
    }

    printf("%d\n", d[n]);
    return 0;
}
