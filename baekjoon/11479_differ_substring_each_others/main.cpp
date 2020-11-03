#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX = 1e6 + 10;
int sfx[MAX + 1], order[MAX + 1], norder[MAX + 1], aux[MAX + 1], rev[MAX + 1], lcp[MAX + 1];
char str[MAX + 1];
int n;
ll ans = 0;

void solve() {

    int len = 1;
    int cnt[MAX + 10] = {0};
    int cntSize = max(n + 1, 255);

    // init
    for (int i = 0; i < n; ++i) {
        sfx[i] = i;
        order[i] = str[i];
    }

    int ord = 1;
    int cntBufferSz = sizeof cnt;
    while (true) {

        memset(cnt, 0, cntBufferSz);
        for (int i = 0; i < n; ++i) {
            cnt[order[min(n, i + len)]]++;
        }

        for (int i = 1; i < cntSize; ++i) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            aux[--cnt[order[min(n, i + len)]]] = i;
        }

        memset(cnt, 0, cntBufferSz);
        for (int i = 0; i < n; ++i) {
            cnt[order[i]]++;
        }

        for (int i = 1; i < cntSize; ++i) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            sfx[--cnt[order[aux[i]]]] = aux[i];
        }

        if (ord == n) break;

        norder[sfx[0]] = ord = 1;
        for (int i = 1; i < n; ++i) {
            if (order[sfx[i - 1]] != order[sfx[i]] || order[sfx[i - 1] + len] != order[sfx[i] + len]) {
                ord++;
            }
            norder[sfx[i]] = ord;
        }

        memcpy(order, norder, sizeof(int) * n);
        len *= 2;
    }

    for (int i = 0; i < n; ++i) {
        rev[sfx[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (rev[i]) {
            int prev = sfx[rev[i] - 1];
            while (str[i + h] == str[prev + h]) h++;
            lcp[rev[i]] = h;
            ans += (ll) h;
        }

        if (h) h--;
    }

}


int main() {

    scanf("%s", str);
    n = strlen(str);

    solve();

    ll maxi = (ll) n;
    maxi = (maxi * (maxi + 1ll)) / 2ll;
    printf("%lld\n", maxi - ans);

    return 0;
}
