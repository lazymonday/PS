#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 10;
int sfx[MAX + 1], order[MAX + 1], norder[MAX + 1], aux[MAX + 1], rev[MAX + 1], lcp[MAX + 1];
char str[MAX + 1];
int n;

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
        }

        if (h) h--;
    }
}


int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        n = strlen(str);
        solve();

        // print answer
        int ans = lcp[1];
        for (int i = 2; i < n; ++i) {
            if (lcp[i - 1] < lcp[i]) {
                ans += (lcp[i] - lcp[i - 1]);
            }
        }

        printf("%d\n", ans);

        // clear
        memset(str, 0, sizeof str);
        memset(order, 0, sizeof order);
        memset(sfx, 0, sizeof sfx);
        memset(lcp, 0, sizeof lcp);
    }


    return 0;
}
