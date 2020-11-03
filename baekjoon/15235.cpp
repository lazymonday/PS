#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];
int ans[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (a[i]) q.push(i);

    int elapsed = 1;
    while (!q.empty()) {
        int pos = q.front();
        if (a[pos] > 1) {
            q.push(pos);
        } else if (a[pos] == 1) {
            ans[pos] = elapsed;
        }

        a[pos]--;
        q.pop();
        elapsed++;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";

    return 0;
}
