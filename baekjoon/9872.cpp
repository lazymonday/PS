#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string, int> freq;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        sort(s, s + 3);
        string ss(s[0]);
        ss.append(s[1]);
        ss.append(s[2]);
        freq[ss]++;
    }

    int ans = 0;
    for (auto x : freq) {
        ans = max(ans, x.second);
    }

    cout << ans;

    return 0;
}
