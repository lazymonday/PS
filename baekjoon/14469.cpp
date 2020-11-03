#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 1e9;
typedef long long ll;

int n;
pair<int, int> tt[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tt[i].first >> tt[i].second;
    }

    sort(tt, tt + n);

    int cur = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cur <= tt[i].first) {
            cur = tt[i].first + tt[i].second;
        } else {
            cur += tt[i].second;
        }
    }

    cout << cur;

    return 0;
}
