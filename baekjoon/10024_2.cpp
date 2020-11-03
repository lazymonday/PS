#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];
int b[MAX + 1];
int pos[MAX + 1];   // where in b
int seen[MAX + 1];

int check_cycle(int start) {

    int ret = 1;
    int p = pos[a[start]];
    while (p != start) {
        seen[p] = 1;
        p = pos[a[p]];
        ret++;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("reorder/3.in", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        pos[b[i]] = i;
    }

    int num = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != b[i] && !seen[i]) {
            int len = check_cycle(i);
            cnt = max(cnt, len);
            num++;
        }
    }

    cout << num << " " << (cnt == 0 ? -1 : cnt);

    return 0;
}
