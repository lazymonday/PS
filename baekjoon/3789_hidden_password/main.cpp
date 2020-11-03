#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 2e5;
char str[MAX + 1];
int sfx[MAX + 1], rev[MAX + 1], order[MAX + 1], newOrder[MAX + 1], aux[MAX + 1], lcp[MAX + 1];
int n;

void solve() {

    memset(sfx, 0, sizeof sfx);
    memset(order, 0, sizeof order);
    memset(lcp, 0, sizeof lcp);

    for (int i = 0; i < n; ++i) {
        sfx[i] = i;
        order[i] = str[i];
    }

    int cnt[MAX + 1];
    int cntMax = max(n, 255);
    int len = 1;
    int pnt = 1;
    while (true) {
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; ++i) {
            cnt[order[min(n, len + i)]]++;
        }
        for (int i = 1; i <= cntMax; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            aux[--cnt[order[min(n, len + i)]]] = i;
        }

        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            cnt[order[i]]++;
        }
        for (int i = 1; i <= cntMax; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            sfx[--cnt[order[aux[i]]]] = aux[i];
        }

        if (pnt == n) {
            break;
        }

        newOrder[sfx[0]] = pnt = 1;
        for (int i = 1; i < n; ++i) {
            if (order[sfx[i]] != order[sfx[i - 1]] || order[sfx[i] + len] != order[sfx[i - 1] + len]) {
                ++pnt;
            }
            newOrder[sfx[i]] = pnt;
        }

        memcpy(order, newOrder, sizeof(int) * n);

        len *= 2;
    }

    for (int i = 0; i < n; ++i) {
        rev[sfx[i]] = i;
    }

    int h = 0;
    for (int i = 1; i < n; ++i) {
        if (rev[i]) {
            int prev = sfx[rev[i] - 1];
            while (str[prev + h] == str[i + h]) ++h;
            lcp[rev[i]] = h;
        }

        if (h) --h;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l >> str;
        n = l;
        memcpy(str + l, str, l);
        n = l * 2;
        str[n] = '\0';

        solve();

        int ans = INF;
        for (int i = 0; i < n; ++i) {
            if (ans != INF && sfx[i] >= l) {
                break;
            }

            if (0 < sfx[i] && sfx[i] < l) {
                ans = min(ans, sfx[i]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
