#include <cstdio>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;
const int INF = 2e9;
const int MAX = 100;
int n, m;
int mem[MAX + 1];
int cost[MAX + 1];
ll dp[10001];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &mem[i]);
    }

    int costMax = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cost[i]);
        costMax += cost[i];
    }

    int ans = INF;
    for (int j = 1; j <= n; ++j) {
        for (int i = costMax; i >= cost[j]; --i) {
            dp[i] = MAX(dp[i], dp[i - cost[j]] + 1ll * mem[j]);
            if (dp[i] >= m) {
                ans = MIN(ans, i);
            }
        }
    }

    printf("%d", (ans == INF ? 0 : ans));

    return 0;
}
