#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e5;
typedef long long ll;

int n;
pair<int, int> a[MAX + 1];
pair<int, int> b[MAX + 1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int r, c;
    b[n] = a[n] = {1e6 + 1, 1e6 + 1};
    for (int i = 0; i < n; ++i)
    {
        cin >> r >> c;
        a[i] = {r, c};
        b[i] = {c, r};
    }

    sort(a, a + n);
    sort(b, b + n);

    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        int left[2] = {i + 1, 0}, right[2] = {n - i - 1, 0};
        for (int j = 0; j < n; ++j)
        {
            if (b[j].second <= a[i].first) {
                left[0]--;
                left[1]++;
            } else {
                right[0]--;
                right[1]++;
            }

            if (a[i + 1].first != a[i].first && b[j + 1].first != b[j].first) {
                ans = min(ans, max({left[0], left[1], right[0], right[1]}));
            }
        }
    }

    cout << ans;
}