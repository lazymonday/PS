#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int INF = 1e9;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int len = s.size();
    int tlen = t.size();

    char ans[MAX + 5];
    int cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        ans[cnt++] = s[i];

        if (cnt >= tlen) {
            bool same = true;
            for (int j = 0; j < tlen; ++j) {
                if (ans[cnt - j - 1] != t[tlen - 1 - j]) { same = false; break; }
            }

            if (same) cnt -= tlen;
        }
    }

    ans[cnt] = 0;
    cout << ans;

    return 0;
}
