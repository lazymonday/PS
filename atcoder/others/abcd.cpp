#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int, pair<int, int>> cand;

    const int N = 1000;
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            int result = i * i * i + j * j * j;
            if (cand.find(result) == cand.end()) {
                cand.insert({result, {i, j}});
            } else {
                //cout << cand[result].first << ", " << cand[result].second << " = " << i << ", " << j << "\n";
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
