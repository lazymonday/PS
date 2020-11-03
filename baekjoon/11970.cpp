#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    for (int i = 0; i <= 100; ++i)
    {
        if ((a <= i && i < b) ||
                (c <= i && i < d)) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
