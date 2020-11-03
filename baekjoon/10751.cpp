#include <cstdio>

const int MAX = 1e5;
const int INF = 1e9;
typedef long long ll;

int n;
char s[MAX + 1];

int main() {
    scanf("%d %s", &n, s);
    ll accum = 0;
    ll ans = 0;
    int w = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'C') {
            ans += accum;
        } else if (s[i] == 'O') {
            accum += w;
        } else if (s[i] == 'W') {
            w++;
        }
    }

    printf("%lld", ans);

    return 0;
}
