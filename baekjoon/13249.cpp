#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;
const int INF = 1e9;
typedef long long ll;

int n;
int a[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int t;
    cin >> t;

    sort(a, a + n);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] + t * 2 >= a[j]) cnt++;
        }
    }

    cout << (double)cnt * 0.25;
    return 0;
}
