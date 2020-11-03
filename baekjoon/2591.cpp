#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e6;
const int INF = 2e9;
typedef long long ll;
int dp[100];

int solve(string str, int idx) {
    if (str.size() == 0) {
        return 1;
    }

    int& ret = dp[idx];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i = 1; i <= 34; ++i)
    {
        int sz = (i >= 10 ? 2 : 1);
        if (str.size() < sz) continue;
        string ss = str.substr(str.size() - sz);
        int k = atoi(ss.c_str());
        if (k == i) {
            ret += solve(str.substr(0, str.size() - sz), idx + sz);
        }
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);

    string s;
    cin >> s;

    solve(s, 0);
    cout << dp[0];

    return 0;
}
