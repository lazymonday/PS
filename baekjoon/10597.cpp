#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
const int INF = 1e9;
typedef long long ll;

bool a[55];

bool solve(int pos, int offset, string& s, vector<int>& ans) {
    if (pos + offset > s.size()) {
        for (int i = 0; i < ans.size(); ++i)
        {
            if (!a[i + 1]) return false;
        }

        for (auto x : ans) cout << x << " ";
        return true;
    }

    int k;
    if (offset == 0) {
        k = s[pos] - '0';
    } else {
        k = (s[pos] - '0') * 10 + s[pos + offset] - '0';
    }

    if (k == 0 || k > 50 || a[k]) return false;

    a[k] = true;
    ans.push_back(k);
    bool ret = solve(pos + 1 + offset, 0, s, ans);
    if (!ret) {
        ret = solve(pos + 1 + offset, 1, s, ans);
    }

    ans.pop_back();
    a[k] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> ans;
    if (!solve(0, 0, s, ans)) {
        solve(0, 1, s, ans);
    }

    return 0;
}
