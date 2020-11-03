#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int INF = 1e9;
typedef long long ll;

int a[MAX + 1];
int b[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        int ret = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            b[i] = b[i - 1] + a[i];
        }

        int qmax = *max_element(a+1, a+n+1);
        if(qmax < 0) {
            cout << qmax << "\n";
            continue;
        }

        int minv = 0;
        for (int i = 1; i <= n; ++i)
        {
            ret = max(ret, b[i] - minv);
            minv = min(minv, b[i]);
        }

        cout << ret << "\n";
    }

    return 0;
}
