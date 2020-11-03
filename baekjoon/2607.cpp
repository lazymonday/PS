#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;

int s[101][26];

bool similar(int i, int j) {
    int diff = 0;
    int l1 = 0, l2 = 0;

    for (int k = 0; k < 26; ++k)
    {
        diff += abs(s[i][k] - s[j][k]);
        l1 += s[i][k];
        l2 += s[j][k];
    }

    return (diff <= 2 && abs(l1 - l2) <= 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); ++j)
        {
            s[i][str[j] - 'A']++;
        }

        if (i == 0) continue;
        if (similar(0, i)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
