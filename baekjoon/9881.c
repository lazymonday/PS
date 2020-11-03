#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int INF = 1e9;
typedef long long ll;

int n;
int hills[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> hills[i];
    }

    sort(hills, hills + n);

    int ans = INF;
    for (int i = 0; i <= 83; ++i)
    {
        int cand = 0;
        for (int j = 0; j < n; ++j)
        {
            int val = 0;
            if (hills[j] < i) {
                val = i - hills[j];
            } else if (hills[j] > i + 17) {
                val = hills[j] - i - 17;
            }
            cand += val * val;
        }
        ans = min(ans, cand);
    }

    cout << ans;
    return 0;
}
